#pragma once
#include "../codeBlocks/CodeBlock.h"
#include <vector>
#include <memory>
#include <print>
#include <string>
#include <string_view>
#include <cstddef>
#include "Character.h"

class Player : public Character
{
    private:
    std::vector<std::unique_ptr<CodeBlock>> m_blocks {};
    bool m_defeated { false };
    

    public:
    using SV = std::string_view;

    Player() = default;
    constexpr Player(SV name, int hp, int atk) : Character{name,hp,atk} { }
    
    bool isDefeated() const { return m_defeated; }
    void showStats() const 
    {
        std::println("{}, HP: {}, ATK: {}", getName(), getHp(), getAtk());
    }

    void clearAndResizeIDE(std::size_t lineCount)
    {
        clearIDE();
        m_blocks.resize(lineCount);
    }
    void clearIDE()
    {
        std::size_t size { m_blocks.size() };
        clearAndResizeIDE(size);
    }

};