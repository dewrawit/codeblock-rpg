#pragma once

#include <string>
#include <string_view>
#include <iostream>
#include <functional>
#include <variant>

class Context;
class Player;

class CodeBlock
{
    public:
    using BlockValue = std::variant<std::monostate,int>;

    using NoArgFunction = std::function<BlockValue(Context&)>;
    using OneIntFunction = std::function<BlockValue(Context&,int)>;
    using PlayerIntFunction = std::function<BlockValue(Context&, Player&, int)>;
    using TwoIntFunction = std::function<BlockValue(Context&, int, int)>;
    using SV = std::string_view;

    enum class Type { empty, noArgs, oneInt, playerInt, twoInt };
    enum class Rarity { common, rare, epic };
    enum class OutputType { none, integer };

    private:
    Type m_type{ Type::empty };
    Rarity m_rarity{};
    OutputType m_outputType{};
    std::string m_displayText{};

    public:
    CodeBlock() = default;
    virtual ~CodeBlock() = default;
    CodeBlock(Type type, Rarity rarity, OutputType outputType, SV display) 
        : m_type{ type }
        , m_rarity{ rarity }
        , m_outputType{ outputType }
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