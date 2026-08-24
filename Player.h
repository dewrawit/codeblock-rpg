#pragma once
#include "CodeBlock.h"
#include <vector>
#include <memory>

class CodeBlock;

class Player
{
    private:
    int m_hp {};
    int m_atk {};
    std::vector<std::unique_ptr<CodeBlock>> m_blocks {};

    public:
    Player() = default;
    Player(int hp, int atk) : m_hp{ hp }, m_atk{ atk } { }

    int getHp() const { return m_hp; }
    int getAtk() const { return m_atk; }

};