#pragma once
#include "CodeBlock.h"

class NoArgBlock : public CodeBlock
{
    NoArgFunction m_func {};

    NoArgBlock(Type type, Rarity rarity, OutputType outputType , SV display, 
        const NoArgFunction& func) 
        : CodeBlock{ type, rarity, outputType, display }
        , m_func{ func }
    { }
};

class OneIntBlock : public CodeBlock
{
    OneIntFunction m_func {};

    OneIntBlock(Type type, Rarity rarity, OutputType outputType, SV display, 
        const OneIntFunction& func) 
        : CodeBlock{ type, rarity, outputType, display }
        , m_func{ func }
    { }
};

class TwoIntBlock : public CodeBlock
{
    TwoIntFunction m_func {};

    TwoIntBlock(Type type, Rarity rarity, OutputType outputType, SV display, 
        const TwoIntFunction& func) 
        : CodeBlock{ type, rarity, outputType, display }
        , m_func{ func }
    { }
};

class PlayerIntBlock : public CodeBlock
{
    PlayerIntFunction m_func {};

    PlayerIntBlock(Type type, Rarity rarity, OutputType outputType, SV display, 
        const PlayerIntFunction& func) 
        : CodeBlock{ type, rarity, outputType, display }
        , m_func{ func }
    { }
};