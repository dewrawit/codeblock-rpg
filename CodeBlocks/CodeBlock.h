#pragma once

#include <string>
#include <string_view>
#include <iostream>

class CodeBlock
{
    public:
    enum class Type { variable, action, flow, modify };

    private:
    Type m_type{};
    std::string m_displayText{};

    public:
    using SV = std::string_view;

    CodeBlock() = default;
    ~CodeBlock() = default;
    CodeBlock(Type type) : m_type{ type } { }

    Type getType() const { return m_type; }
    SV getDisplayText() const { return m_displayText; }

    friend std::ostream& operator<<(std::ostream& out, const CodeBlock& cb)
    {
        out << "[ " << cb.m_displayText << " ]";
        return out;
    }
};