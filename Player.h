#pragma once
#include "CodeBlocks/CodeBlock.h"
#include <vector>
#include <memory>
#include <print>
#include <string>
#include <string_view>

class CodeBlock;

class Player
{
    private:
    std::string m_name {};
    int m_hp {};
    int m_atk {};
    std::vector<std::unique_ptr<CodeBlock>> m_blocks {};
    bool m_defeated { false };
    

    public:
    using SV = std::string_view;

    Player() = default;
    constexpr Player(SV name, int hp, int atk) 
        : m_name{ name }
        , m_hp{ hp }
        , m_atk{ atk } 
        { }

    int getHp() const { return m_hp; }
    int getAtk() const { return m_atk; }
    const std::string& getName() const { return m_name; }
    bool isDefeated() const { return m_defeated; }
    void showStats() const 
    {
        std::println("{}, HP: {}, ATK: {}", getName(), getHp(), getAtk());
    }

};