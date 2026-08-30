#pragma once
#include "CodeBlock.h"
#include "Random.h"
#include "BlockDatabase.h"
#include <memory>
#include <type_traits>
#include <cassert>
#include <vector>
#include <array>

class CodeBlockPool
{
    private:
    using RarityCatagorizedPool = 
    std::array<
        std::vector<std::unique_ptr<CodeBlock>>,
        static_cast<std::size_t>(CodeBlock::Rarity::maxRarityCount)
    >;

    RarityCatagorizedPool m_allBlocks {};

    std::vector<std::unique_ptr<CodeBlock>> m_pool {};


    public:
    using SV = std::string_view;

    template <typename BlockType>
    std::unique_ptr<CodeBlock> makeBlock(CodeBlock::Type t, CodeBlock::Rarity r, SV dis) const
    {
        //Check if template has same type or derived from CodeBlock
        static_assert(std::is_base_of_v<CodeBlock,BlockType> && "Unrelated class in makeBlock");

        return std::make_unique<BlockType>(t,r,dis);
    }

    CodeBlockPool(std::size_t size)
    {
        m_pool.resize(size);

        BlockDatabase blockDatabase {};
        receiveAllBlocksInfo(blockDatabase);
    }
    void fillRandomBlocks()
    {
        for(auto i {0uz}; i < m_pool.size(); ++i)
        {
            m_pool[i] = generateRandomCodeBlock();
        }
    }
    static std::unique_ptr<CodeBlock> generateRandomCodeBlock()
    {
        return std::make_unique<CodeBlock>();
    }
    void receiveAllBlocksInfo(const BlockDatabase& blockDatabase)
    {   
        using ST = std::size_t;

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
        for(const auto& row : m_allBlocks)
        {
            for(const auto& blockPtr : row)
            {
                std::cout << *blockPtr << ' ';
            }
            std::cout << '\n';
        }
    }
};