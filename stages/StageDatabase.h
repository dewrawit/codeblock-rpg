#pragma once
#include "Stage.h"
#include "../entities/EnemyDatabase.h"
#include "../keys/Key.h"
#include <unordered_map>
#include <string_view>
#include <cassert>

class StageDatabase
{
    private:
    using SV = std::string_view;
    std::unordered_map<std::string_view,Stage> m_stages {};

    public:
    Stage createStage(SV key) const
    {
        assert(m_stages.contains(key) && "createStage key not in StageDatabase");

        return m_stages.at(key);
    }
    StageDatabase(const EnemyDatabase& enemyDatabase)
    {
        m_stages.emplace(Key::Stage::Python, Stage{Key::Stage::Python});
        
        m_stages[Key::Stage::Python].add(enemyDatabase.createEnemy(Key::Enemy::BlueSnake));
        m_stages[Key::Stage::Python].add(enemyDatabase.createEnemy(Key::Enemy::YellowSnake));
        m_stages[Key::Stage::Python].add(enemyDatabase.createEnemy(Key::Enemy::PyAConda));
        m_stages[Key::Stage::Python].add(enemyDatabase.createEnemy(Key::Enemy::PythonChan));
    }

    //TBD option to restore the stage if player quit (like megaman)
};