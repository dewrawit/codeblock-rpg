#pragma once
#include "entities/Player.h"
#include <memory>

class Context
{
    private:
    Player* m_player{ nullptr };
    Player* m_opponent{ nullptr }; //GameState has Data of opponent, context references it

    Player* m_caller{ nullptr }; //Who owns that code

    public:
    Context() = default;
    Context(Player& player) //Context can modify Player, so parameter must be non const
        : m_player{ &player }
        { }
    Context(Player& player, Player& enemy)
        : m_player{ &player }, m_opponent{ &enemy }
        { }

    const Player& getPlayer() const { return *m_player; }
    Player& getPlayer() { return *m_player; }

    const Player& getOpponent() const { return *m_opponent; }
    Player& getOpponent() { return *m_opponent; }
    
    void setOpponent(Player& enemy) { m_opponent = &enemy; }
    const Player& getCaller() const { return *m_caller; }
    Player& getCaller() { return *m_caller; }

};