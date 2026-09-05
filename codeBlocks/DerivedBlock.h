#pragma once
#include "CodeBlock.h"
#include <array>
#include <print>
#include <memory>

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

    BlockValue run(Context& context) const override
    {
        return m_func(context);
    }
};
//TBD implement how int parameter work
class OneIntBlock : public CodeBlock
{
    private:
    OneIntFunction m_func {};
    std::unique_ptr<CodeBlock> m_intArg { nullptr };

    public:
    OneIntBlock(Type type, Rarity rarity, OutputType outputType, SV display, 
        const OneIntFunction& func) 
        : CodeBlock{ type, rarity, outputType, display }
        , m_func{ func }
    { }

    std::unique_ptr<CodeBlock> clone() const override
    {
        //Cannot use copy constructor 
        //because this derived class stores unique ptr which can't be copied
        //return std::make_unique<OneIntBlock>(*this);

        //intArg is always nullptr when cloning (invariant)
        return std::make_unique<OneIntBlock>(
            m_type,
            m_rarity,
            m_outputType,
            m_displayText,
            m_func
        );
    }
    virtual void print(std::ostream& out) const override
    {
        out << "[ (" << rarityToStr() << ") "
        << m_displayText << " ( " << (m_intArg ? m_intArg->getDisplayText() : "") << " ) ]";
    }
    // std::unique_ptr<CodeBlock>& getArgBlock()
    // {
    //     return m_intArg;
    // } 
    void setArgBlock(std::unique_ptr<CodeBlock>& intBlock)
    {
        m_intArg = std::move(intBlock);
    }
    BlockValue run(Context& context) const override
    {   
        if(m_intArg == nullptr || m_intArg->getOutputType() != OutputType::integer)
        {
            std::println("Syntax Error! Argument must have int value.");
            return std::monostate{};
        }
        else
        {
            int value { std::get<int>(m_intArg->run(context)) };

            return m_func(context, value);
        }
   }
};

// class TwoIntBlock : public CodeBlock
// {
//     private:
//     TwoIntFunction m_func {};
    

//     public:
//     TwoIntBlock(Type type, Rarity rarity, OutputType outputType, SV display, 
//         const TwoIntFunction& func) 
//         : CodeBlock{ type, rarity, outputType, display }
//         , m_func{ func }
//     { }

//     std::unique_ptr<CodeBlock> clone() const override
//     {
//         return std::make_unique<TwoIntBlock>(*this);
//     }
// };

// class PlayerIntBlock : public CodeBlock
// {
//     private:
//     PlayerIntFunction m_func {};

//     public:
//     PlayerIntBlock(Type type, Rarity rarity, OutputType outputType, SV display, 
//         const PlayerIntFunction& func) 
//         : CodeBlock{ type, rarity, outputType, display }
//         , m_func{ func }
//     { }

//     std::unique_ptr<CodeBlock> clone() const override
//     {
//         return std::make_unique<PlayerIntBlock>(*this);
//     }
// };