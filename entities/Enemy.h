#pragma once
#include "EnemyInfo.h"
#include "Character.h"
#include <string>
#include <functional>

class Context;

class Enemy : public Character
{
    private:
    using BehaviorFunc = std::function<void(Enemy&, Context&)>;

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

    void takeTurn(Context& context)
    {
        m_behavior(*this, context);
    }
    BehaviorFunc getBehavior() const { return m_behavior; }
};