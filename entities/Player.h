#pragma once
#include "../codeBlocks/CodeBlock.h"
#include <vector>
#include <memory>
#include <print>
#include <string>
#include <string_view>
#include <cstddef>
#include <iostream>
#include "Character.h"

class Player : public Character
{
    private:
    using IDE = std::vector<std::unique_ptr<CodeBlock>>;

    IDE m_blocks {};
    bool m_defeated { false };
    

    public:
    using SV = std::string_view;

    Player() = default;
    constexpr Player(SV name, int hp, int atk) : Character{name,hp,atk} { }

    const IDE& getIDE() const { return m_blocks; }
    IDE& getIDE() { return m_blocks; }
    
    bool isDefeated() const { return m_defeated; }
    void showStats() const 
    {
        std::println("{}, HP: {}, ATK: {}", getName(), getHp(), getAtk());
    }

    void clearAndResizeIDE(std::size_t lineCount)
    {
        m_blocks.clear();
        m_blocks.resize(lineCount);
        clearIDE();
    }
    void clearIDE()
    {
        for(auto& block : m_blocks)
        {
            block = nullptr;
        }
    }
    void printIDE()
    {
        std::println("Your Code: ");
        std::println("-----------------------------------");
        for(auto i {0uz}; i < m_blocks.size(); ++i)
        {
            std::cout << i + 1 << " >> ";

            if(m_blocks[i] == nullptr)
            {
                std::cout << "[EMPTY]";
            }
            else
            {
                std::cout << *m_blocks[i];
            }
            std::println();
        }
        std::println("-----------------------------------");
    }
};