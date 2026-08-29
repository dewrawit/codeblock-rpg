#pragma once
#include "Stage.h"
#include "../entities/EnemyDatabase.h"
#include "../keys/Key.h"
#include <unordered_map>

#include <string>
#include <cassert>

class StageDatabase
{
    private:
    std::unordered_map<std::string,Stage> m_stages {};

    public:
    Stage createStage(const std::string& key) const
    {
        return m_stages.at(key); //if this key doesn't exist it will safely fail the program
    }
    StageDatabase(const EnemyDatabase& enemyDatabase)
    {
        m_stages.emplace(Key::Stage::Python, Stage{Key::Stage::Python});
        
        m_stages[Key::Stage::Python].add(enemyDatabase.createEnemy(Key::Enemy::BlueSnake));
        m_stages[Key::Stage::Python].add(enemyDatabase.createEnemy(Key::Enemy::YellowSnake));
        m_stages[Key::Stage::Python].add(enemyDatabase.createEnemy(Key::Enemy::PyAConda));
        m_stages[Key::Stage::Python].add(enemyDatabase.createEnemy(Key::Enemy::PythonChan));

        m_stages.emplace(Key::Stage::C, Stage{Key::Stage::C});

        m_stages[Key::Stage::C].add(enemyDatabase.createEnemy(Key::Enemy::ArrayPillar));
        m_stages[Key::Stage::C].add(enemyDatabase.createEnemy(Key::Enemy::StarTick));
        m_stages[Key::Stage::C].add(enemyDatabase.createEnemy(Key::Enemy::MemoryLeech));
        m_stages[Key::Stage::C].add(enemyDatabase.createEnemy(Key::Enemy::PointBeetle));
        m_stages[Key::Stage::C].add(enemyDatabase.createEnemy(Key::Enemy::CChan));

        m_stages.emplace(Key::Stage::Cpp, Stage{Key::Stage::Cpp});

        m_stages[Key::Stage::Cpp].add(enemyDatabase.createEnemy(Key::Enemy::SegFlea));
        m_stages[Key::Stage::Cpp].add(enemyDatabase.createEnemy(Key::Enemy::RaiiFly));
        m_stages[Key::Stage::Cpp].add(enemyDatabase.createEnemy(Key::Enemy::TempTula));
        m_stages[Key::Stage::Cpp].add(enemyDatabase.createEnemy(Key::Enemy::CppChan));

    }

    //TBD option to restore the stage if player quit (like megaman)
};