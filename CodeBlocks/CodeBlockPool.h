#pragma once
#include "CodeBlock.h"
#include "Random.h"
#include <memory>
#include <type_traits>
#include <cassert>

class CodeBlockPool
{
    private:
    std::vector<std::unique_ptr<CodeBlock>> m_pool {};

    public:
    using SV = std::string_view;

    template <typename BlockType>
    std::unique_ptr<BlockType> makeBlock(CodeBlock::Type t, CodeBlock::Rarity r, SV dis) const
    {
        //Check if template has same type or derived from CodeBlock
        static_assert(std::is_base_of_v<CodeBlock,BlockType> && "Unrelated class in makeBlock");

        return std::make_unique<BlockType>(t,r,dis);
    }

    CodeBlockPool()
    {
        //Create all the code blocks in the game here
        //m_pool.push_back(makeBlock())
        
    }

    static CodeBlock generateRandomCodeBlock()
    {

    }
}