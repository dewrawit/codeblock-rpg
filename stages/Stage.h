#pragma once
#include "../entities/Enemy.h"
#include <queue>
#include <string>
#include <cassert>

class Stage
{
    private:
    std::string m_stageKey{};
    std::queue<Enemy> m_enemies{};   
    
    public:
    Stage() = default;
    Stage(std::string_view stageKey) : m_stageKey{ stageKey } { }

    const std::string& getStageKey() const { return m_stageKey; }

    void add(const Enemy& enemy)
    {
        m_enemies.push(enemy); //copies enemy
    }
    bool cleared() const
    {
        return m_enemies.empty();
    }   
    void popEnemyFromQueue()
    {
        assert(!cleared() && "Attempt to pop an empty stage queue");

        m_enemies.pop();
    }
    //Return by reference, allowing Context to modify enemy stage when player battles it
    const Enemy& getCurrentEnemy() const
    {
        return m_enemies.front();
    }
    Enemy& getCurrentEnemy() 
    {
        return m_enemies.front();
    }
    const Enemy& getBoss() const
    {
        return m_enemies.back();
    }
    Enemy& getBoss() 
    {
        return m_enemies.back();
    }
};