#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include "CodeBlock.h"

class BlockDatabase
{
    private:
    std::unordered_map<std::string,std::unique_ptr<CodeBlock>> m_blockDatabase{};

    public:
    std::unique_ptr<CodeBlock> createBlock(const std::string& key) const
    {
        
    }
    BlockDatabase()
    {
        //emplace block here
    }
};