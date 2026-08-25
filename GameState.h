#pragma once
#include "Context.h"
#include "Game.h"

class GameState
{
    private:
    Context m_context {};
    std::vector<Player> m_enemies {};

    public:
    GameState(const Player& player);

    const Context& getContext() const { return m_context; }
    Context& getContext() { return m_context; }
    void setContext(const Player& player, const Player& enemy)
    {
        //Create when stage start. Kind of like megaman
        m_context = Context{ player, enemy };
    }

    const std::vector<Player>& getEnemiesVector() const { return m_enemies; }
    std::vector<Player>& getEnemiesVector() { return m_enemies; }

    



};