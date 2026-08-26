#pragma once
#include "Context.h"
#include "Game.h"

class GameState
{
    private:
    Player m_player{};
    Context m_context {};
    std::vector<Player> m_enemies {};

    public:
    GameState(Player& player);

    const Context& getContext() const { return m_context; }
    Context& getContext() { return m_context; }

    const Player& getPlayer() const { return m_player; }
    Player& getPlayer() { return m_player; }
    const std::vector<Player>& getEnemiesVector() const { return m_enemies; }
    std::vector<Player>& getEnemiesVector() { return m_enemies; }

    void setupStageContext(int select);


    



};