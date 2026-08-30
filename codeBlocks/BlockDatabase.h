#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include "CodeBlock.h"
#include "DerivedBlock.h"
#include "../keys/Key.h"
#include "../Context.h"

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
        m_blockDatabase.emplace( 
            Key::Block::Five,
                std::make_unique<NoArgBlock>(
                    CodeBlock::Type::noArgs,
                    CodeBlock::Rarity::common,
                    CodeBlock::OutputType::integer,
                    "5",
                    [](Context&) -> int
                    {
                        return 5;
                    }
                )
        );
        m_blockDatabase.emplace( 
            Key::Block::Ten,
                std::make_unique<NoArgBlock>(
                    CodeBlock::Type::noArgs,
                    CodeBlock::Rarity::common,
                    CodeBlock::OutputType::integer,
                    "10",
                    [](Context&) -> int
                    {
                        return 10;
                    }
                )
        );
        m_blockDatabase.emplace( 
            Key::Block::Fifteen,
                std::make_unique<NoArgBlock>(
                    CodeBlock::Type::noArgs,
                    CodeBlock::Rarity::rare,
                    CodeBlock::OutputType::integer,
                    "15",
                    [](Context&) -> int
                    {
                        return 15;
                    }
                )
        );
        m_blockDatabase.emplace( 
            Key::Block::Twenty,
                std::make_unique<NoArgBlock>(
                    CodeBlock::Type::noArgs,
                    CodeBlock::Rarity::rare,
                    CodeBlock::OutputType::integer,
                    "20",
                    [](Context&) -> int
                    {
                        return 20;
                    }
                )
        );

        //Fight functions
        m_blockDatabase.emplace(
            Key::Block::Attack,
            std::make_unique<NoArgBlock>(
                CodeBlock::Type::noArgs,
                CodeBlock::Rarity::common,
                CodeBlock::OutputType::none,
                "Attack",
                [](Context& context) -> void
                {
                    context.getPlayer().attack(context.getActiveEnemy());
                }
            )
        );

        m_blockDatabase.emplace(
            Key::Block::HeavyAttack,
            std::make_unique<NoArgBlock>(
                CodeBlock::Type::noArgs,
                CodeBlock::Rarity::rare,
                CodeBlock::OutputType::none,
                "HeavyAttack",
                [](Context& context) -> void
                {
                    context.getPlayer().attack(context.getActiveEnemy());
                }
            )
        );

        m_blockDatabase.emplace(
            Key::Block::Guard,
            std::make_unique<NoArgBlock>(
                CodeBlock::Type::noArgs,
                CodeBlock::Rarity::common,
                CodeBlock::OutputType::none,
                "Guard",
                [](Context& context) -> void
                {

                }
            )
        );

        m_blockDatabase.emplace(
            Key::Block::Parry,
            std::make_unique<NoArgBlock>(
                CodeBlock::Type::noArgs,
                CodeBlock::Rarity::rare,
                CodeBlock::OutputType::none,
                "Parry",
                [](Context& context) -> void
                {

                }
            )
        );

        m_blockDatabase.emplace(
            Key::Block::Counter,
            std::make_unique<NoArgBlock>(
                CodeBlock::Type::noArgs,
                CodeBlock::Rarity::epic,
                CodeBlock::OutputType::none,
                "Counter",
                [](Context& context) -> void
                {

                }
            )
        );
                     
    }
};