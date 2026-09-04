#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include "CodeBlock.h"
#include "DerivedBlock.h"
#include "../keys/Key.h"
#include "../Context.h"
#include <typeinfo>

class BlockDatabase
{
    private:
    using BlockMap = std::unordered_map<std::string,std::unique_ptr<CodeBlock>>;
    BlockMap m_blockDatabase{};

    public:
    //Clone a unique_ptr from database
    std::unique_ptr<CodeBlock> createBlock(const std::string& key) const
    {
        return m_blockDatabase.at(key)->clone();

        //Doesnt work: .at() return reference / C++ doesn't allow copy unique_ptr 
        //return m_blockDatabase.at(key);

        // Also doesn't work, .at() return a CodeBlock& and has no suitable conversion to derived
        // if(typeid(*m_blockDatabase.at(key)) == typeid(NoArgBlock))
        // {
        //     return std::make_unique<NoArgBlock>(*m_blockDatabase.at(key));
        // }
        // ...and so on for every derived type
      
    }
    const BlockMap& getMap() const
    {
        return m_blockDatabase;
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
                    [](Context&) -> CodeBlock::BlockValue
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
                    [](Context&) -> CodeBlock::BlockValue
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
                    [](Context&) -> CodeBlock::BlockValue
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
                    [](Context&) -> CodeBlock::BlockValue
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
                [](Context& context) -> CodeBlock::BlockValue
                {
                    context.getPlayer().attack(context.getActiveEnemy());
                    return std::monostate{};
                }
            )
        );

        m_blockDatabase.emplace(
            Key::Block::HeavyAttack,
            std::make_unique<NoArgBlock>(
                CodeBlock::Type::noArgs,
                CodeBlock::Rarity::rare,
                CodeBlock::OutputType::none,
                "Heavy Attack",
                [](Context& context) -> CodeBlock::BlockValue
                {
                    context.getPlayer().attack(context.getActiveEnemy());
                    return std::monostate{};
                }
            )
        );

        m_blockDatabase.emplace(
            Key::Block::LifeSteal,
            std::make_unique<NoArgBlock>(
                CodeBlock::Type::noArgs,
                CodeBlock::Rarity::epic,
                CodeBlock::OutputType::none,
                "Life Steal",
                [](Context& context) -> CodeBlock::BlockValue
                {
                    context.getPlayer().attack(context.getActiveEnemy());

                    context.getPlayer().heal(context.getPlayer().getAtk());
                    
                    return std::monostate{};
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
                [](Context& context) -> CodeBlock::BlockValue
                {
                    context.getPlayer().guard();
                    return std::monostate{};
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
                [](Context& context) -> CodeBlock::BlockValue
                {
                    context.getPlayer().superGuard();
                    return std::monostate{};
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
                [](Context& context) -> CodeBlock::BlockValue
                {
                    context.getPlayer().counter();
                    return std::monostate{};
                }
            )
        );
               
    }
};