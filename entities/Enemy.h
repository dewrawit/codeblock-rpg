#pragma once
#include "EnemyInfo.h"
#include "Character.h"
#include <string>
#include <functional>

class Enemy : public Character
{
    private:
    using BehaviorFunc = std::function<void(Enemy&)>;

    int m_actionPerTurn {};
    BehaviorFunc m_behavior {};
    bool m_defeated{ false };

    public:
    Enemy(const EnemyInfo& enemyInfo, const auto& func ) 
        : Character{ enemyInfo.name, enemyInfo.hp, enemyInfo.atk }
        , m_actionPerTurn{ enemyInfo.actionPerTurn }
        , m_behavior{ func }
        { }

    int getActionPerTurn() const { return m_actionPerTurn; }
    bool isDefeated() const { return m_defeated; }

    void takeTurn()
    {
        m_behavior(*this);
    }
    BehaviorFunc getBehavior() const { return m_behavior; }
};