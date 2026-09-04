#pragma once
#include "entities/Player.h"
#include "stages/Stage.h"

#include <memory>

class Enemy;

class Context
{
    private:
    Player* m_player{ nullptr };

    Stage* m_stage{ nullptr }; //GameState has Data of stage, context references it

    Player* m_caller{ nullptr }; //Who owns that code

    int m_turnNumber { 0 };
    int m_actionNumber { 0 };

    public:
    Context() = default;
    Context(Player& player) //Context can modify Player, so parameter must be non const
        : m_player{ &player }
        { }

    const Player& getPlayer() const { return *m_player; }
    Player& getPlayer() { return *m_player; }

    const Stage& getStage() const { return *m_stage; }
    Stage& getStage() { return *m_stage; }
    
    const Enemy& getActiveEnemy() const { return m_stage->getCurrentEnemy(); };
    Enemy& getActiveEnemy() { return m_stage->getCurrentEnemy(); };

    void setStage(Stage& stage) { m_stage = &stage; }
    const Player& getCaller() const { return *m_caller; }
    Player& getCaller() { return *m_caller; }
    
    int getTurnNumber() const
    {
        return m_turnNumber;
    }
    int getActionNumber() const
    {
        return m_actionNumber;
    }
    void resetTurnAndActionNumber()
    {
        m_turnNumber = 0;
        m_actionNumber = 0;
    }
    void resetActionNumber()
    {
        m_actionNumber = 0;
    }
    void incrementTurn()
    {
        ++m_turnNumber;
    }
    void incrementActionNumber()
    {
        ++m_actionNumber;
    }

};