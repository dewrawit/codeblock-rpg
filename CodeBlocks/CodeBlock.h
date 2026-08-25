#pragma once

#include <string>
#include <string_view>
#include <iostream>
#include <functional>
#include "../Context.h"

class CodeBlock
{
    public:
    enum class Type { noArgs, oneInt, playerInt, twoInt };
    enum class Rarity { common, rare, epic };

    private:
    Type m_type{};
    Rarity m_rarity{};
    std::string m_displayText{};

    public:
    using NoArgFunction = std::function<void(Context&)>;
    using OneIntFunction = std::function<void(Context&,int)>;
    using PlayerIntFunction = std::function<void(Context&, Player&, int)>;
    using TwoIntFunction = std::function<void(Context&, int, int)>;

    using SV = std::string_view;


    CodeBlock() = default;
    ~CodeBlock() = default;
    CodeBlock(Type type, Rarity rarity, SV display) 
        : m_type{ type }
        , m_rarity{ rarity }
        , m_displayText{ display }
        { }

    Type getType() const { return m_type; }
    SV getDisplayText() const { return m_displayText; }

    friend std::ostream& operator<<(std::ostream& out, const CodeBlock& cb)
    {
        out << "[ " << cb.m_displayText << " ]";
        return out;
    }
};