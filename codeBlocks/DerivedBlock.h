#pragma once
#include "CodeBlock.h"

class NoArgBlock : public CodeBlock
{
    private:
    NoArgFunction m_func {};

    public:
    NoArgBlock(Type type, Rarity rarity, OutputType outputType , SV display, 
        const NoArgFunction& func) 
        : CodeBlock{ type, rarity, outputType, display }
        , m_func{ func }
    { }

    std::unique_ptr<CodeBlock> clone() const override
    {
        return std::make_unique<NoArgBlock>(*this);
    }

    BlockValue run(Context& context) const
    {
        return m_func(context);
    }
};

class OneIntBlock : public CodeBlock
{
    private:
    OneIntFunction m_func {};

    public:
    OneIntBlock(Type type, Rarity rarity, OutputType outputType, SV display, 
        const OneIntFunction& func) 
        : CodeBlock{ type, rarity, outputType, display }
        , m_func{ func }
    { }

    std::unique_ptr<CodeBlock> clone() const override
    {
        return std::make_unique<OneIntBlock>(*this);
    }
};

class TwoIntBlock : public CodeBlock
{
    private:
    TwoIntFunction m_func {};

    public:
    TwoIntBlock(Type type, Rarity rarity, OutputType outputType, SV display, 
        const TwoIntFunction& func) 
        : CodeBlock{ type, rarity, outputType, display }
        , m_func{ func }
    { }

    std::unique_ptr<CodeBlock> clone() const override
    {
        return std::make_unique<TwoIntBlock>(*this);
    }
};

class PlayerIntBlock : public CodeBlock
{
    private:
    PlayerIntFunction m_func {};

    public:
    PlayerIntBlock(Type type, Rarity rarity, OutputType outputType, SV display, 
        const PlayerIntFunction& func) 
        : CodeBlock{ type, rarity, outputType, display }
        , m_func{ func }
    { }

    std::unique_ptr<CodeBlock> clone() const override
    {
        return std::make_unique<PlayerIntBlock>(*this);
    }
};