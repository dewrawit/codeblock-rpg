#pragma once

#include <string>
#include <string_view>

class CodeBlock
{
    public:
    enum class Type { variable, number, action, condition };

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
};