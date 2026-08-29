#pragma once
#include "CodeBlock.h"

class NoArgBlock : public CodeBlock
{
    NoArgFunction m_func {};

    NoArgBlock(Type type, Rarity rarity, SV display, const auto& func) 
        : CodeBlock{ type, rarity, display }
        , m_func{ func }
    { }
};

class OneIntBlock : public CodeBlock
{
    OneIntFunction m_func {};

    OneIntBlock(Type type, Rarity rarity, SV display, const auto& func) 
        : CodeBlock{ type, rarity, display }
        , m_func{ func }
    { }
};

class TwoIntBlock : public CodeBlock
{
    TwoIntFunction m_func {};

    TwoIntBlock(Type type, Rarity rarity, SV display, const auto& func) 
        : CodeBlock{ type, rarity, display }
        , m_func{ func }
    { }
};

class PlayerIntBlock : public CodeBlock
{
    PlayerIntFunction m_func {};

    PlayerIntBlock(Type type, Rarity rarity, SV display, const auto& func) 
        : CodeBlock{ type, rarity, display }
        , m_func{ func }
    { }
};