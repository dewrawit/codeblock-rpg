#pragma once
#include "Player.h"
#include <memory>
class Context
{
    private:
    Player m_player{};
    Player m_opponent{}; //GameState has Data of opponent

    Player* m_caller{}; //Who owns that code

    public:
    Context() = default;
    Context(const Player& player, const Player& opponent)
        : m_player{ player }
        , m_opponent{ opponent }
        { }

    const Player& getPlayer() const { return m_player; }
    Player& getPlayer() { return m_player; }
    const Player& getOpponent() const { return m_player; }
    Player& getOpponent() { return m_player; }
    const Player& getCaller() const { return *m_caller; }
    Player& getCaller() { return *m_caller; }

};