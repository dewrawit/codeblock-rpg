#pragma once

#include <string>
#include <string_view>
#include <iostream>
#include <functional>
#include <variant>
#include <memory>
#include <cassert>

class Context;
class Player;

class CodeBlock
{
    public:
    using BlockValue = std::variant<std::monostate,int>; //monostate = no value

    using NoArgFunction = std::function<BlockValue(Context&)>;
    using OneIntFunction = std::function<BlockValue(Context&,int)>;
    using PlayerIntFunction = std::function<BlockValue(Context&, Player&, int)>;
    using TwoIntFunction = std::function<BlockValue(Context&, int, int)>;
    using SV = std::string_view;

    enum class Type { empty, noArgs, oneInt, playerInt, twoInt };
    enum class Rarity { common = 0, rare = 1, epic = 2, maxRarityCount = 3};
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
    Rarity getRarity() const { return m_rarity; }
    OutputType getOutputType() const { return m_outputType; }
    SV getDisplayText() const { return m_displayText; }
    SV rarityToStr() const {
        switch(m_rarity)
        {
            case Rarity::common: return "Common";
            case Rarity::rare: return "Rare";
            case Rarity::epic: return "Epic";
            default: assert(false && "Cannot convert invalid rarity to string");
        }
    }

    virtual std::unique_ptr<CodeBlock> clone() const
    {
        return std::make_unique<CodeBlock>(*this);
    }

    friend std::ostream& operator<<(std::ostream& out, const CodeBlock& cb)
    {
        out << "[ ( " << cb.rarityToStr() << " ) " << cb.m_displayText << " ]";
        return out;
    }

    virtual BlockValue run(Context&) const
    {
        assert(false && "Running Base CodeBlock run function.");
        return std::monostate{};
    }
};