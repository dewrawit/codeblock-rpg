#pragma once
#include "CodeBlock.h"
#include "Random.h"
#include "BlockDatabase.h"
#include <memory>
#include <type_traits>
#include <cassert>
#include <vector>
#include <array>
#include <utility>
#include <print>

class CodeBlockPool
{
    private:
    using ST = std::size_t;
    using RarityCatagorizedPool = 
    std::array<
        std::vector<std::unique_ptr<CodeBlock>>,
        static_cast<std::size_t>(CodeBlock::Rarity::maxRarityCount)
    >;

    RarityCatagorizedPool m_allBlocks {};

    std::vector<std::unique_ptr<CodeBlock>> m_pool {};


    public:
    using SV = std::string_view;

    CodeBlockPool(ST size)
    {
        m_pool.resize(size);

        BlockDatabase blockDatabase {};
        receiveAllBlocksInfo(blockDatabase);
    }

    std::unique_ptr<CodeBlock>& operator[](std::size_t index)
    {
        return m_pool[index];
    }
    void fillRandomBlocks()
    {
        for(auto i {0uz}; i < m_pool.size(); ++i)
        {
            m_pool[i] = generateRandomCodeBlock();
        }
    }
    std::size_t getPoolSize()
    {
        return m_pool.size();
    }
    void removeBlockAtIndex(std::size_t index)
    {
        assert(m_pool.size() > index && "Attempt to remove out of bound index (CodeBlockPool)");
        m_pool.erase(m_pool.begin() + static_cast<std::ptrdiff_t>(index));
    }
    std::unique_ptr<CodeBlock> getRandomBlockFixedRarity(CodeBlock::Rarity rarityIndex)
    {
        const auto& rarityBlockRow { m_allBlocks[static_cast<ST>(rarityIndex)] };
        assert(!rarityBlockRow.empty() && "A rarity has no blocks, cannot generate");

        ST maxIndex { rarityBlockRow.size() - 1 };
        ST rng { Random::get<ST>(0,maxIndex) };

        return rarityBlockRow[rng]->clone();
    }
    std::unique_ptr<CodeBlock> generateRandomCodeBlock()
    {
    
        constexpr std::array< std::pair<CodeBlock::Rarity, int>,
        static_cast<ST>(CodeBlock::Rarity::maxRarityCount) > dropRate
        {
            std::pair{CodeBlock::Rarity::common, 70}, //Common = 1-70
            std::pair{CodeBlock::Rarity::rare, 90}, //Rare = 71-90
            std::pair{CodeBlock::Rarity::epic, 100}, //Epic = 91-100
        };

        int rng { Random::get(1,100) };

        for(const auto& [rarity, rate] : dropRate)
        {
            if(rng <= rate)
            {
                return getRandomBlockFixedRarity(rarity);
            }
        }
        assert(false && "No drop, maybe rate accumulation is wrong?");
    }
    void receiveAllBlocksInfo(const BlockDatabase& blockDatabase)
    {   
        for(const auto& [ key , blockPtr ] : blockDatabase.getMap())
        {
            ST rarityIndex {};
            switch(blockPtr->getRarity())
            {
                case CodeBlock::Rarity::common: 
                    rarityIndex = static_cast<ST>(CodeBlock::Rarity::common);
                    break;
                case CodeBlock::Rarity::rare:
                    rarityIndex = static_cast<ST>(CodeBlock::Rarity::rare);
                    break;
                case CodeBlock::Rarity::epic:
                    rarityIndex = static_cast<ST>(CodeBlock::Rarity::epic);
                    break;
                default: assert(false && "BlockDatabase contains invalid rarity block");
            }
            m_allBlocks[rarityIndex].push_back(blockDatabase.createBlock(key));
        }
    }
    //For testing
    void printAllBlocks()
    {
        std::println("All blocks in the game: ");

        for(const auto& row : m_allBlocks)
        {
            for(const auto& blockPtr : row)
            {
                std::cout << *blockPtr << ' ';
            }
            std::cout << '\n';
        }
    }
    void shufflePool()
    {
        for(auto i { m_pool.size() - 1 }; i > 0; --i )
        {
            //unique_ptr has a special overload for swap, so it works
            std::swap(m_pool[i], m_pool[Random::get(0uz, i)]);
        }
    }
    void printPool()
    {
        std::println("---------------Your Pool---------------\n");

        for(auto i {1uz}; i <= m_pool.size(); ++i)
        {
            std::cout << i << "." << *m_pool[i - 1] << ' ';

            if(i % 5 == 0 && i != m_pool.size())
                std::cout << '\n';
        }

        std::println("\n\n---------------------------------------\n");
    }
};