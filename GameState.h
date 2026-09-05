#pragma once
#include "Context.h"
#include "Game.h"
#include "stages/Stage.h"
#include "entities/EnemyDatabase.h"
#include "stages/StageDatabase.h"
#include <cstddef>

class GameState
{
    public:
    enum class StageIndex { python, /*c, cpp,*/ maxStages };

    private:
    EnemyDatabase m_enemyDatabase {};
    StageDatabase m_stageDatabase { m_enemyDatabase };

    Player m_player{};
    Context m_context {};

    std::vector<Stage> m_stages {}; //Context

    public:
    GameState(Player& player);

    const Context& getContext() const { return m_context; }
    Context& getContext() { return m_context; }

    const Player& getPlayer() const { return m_player; }
    Player& getPlayer() { return m_player; }
    const std::vector<Stage>& getStageVector() const { return m_stages; }
    std::vector<Stage>& getStageVector() { return m_stages; }

    void setupStageContext(int select);
    void restoreStage(StageIndex stageIndex);

    bool gameWon() const
    {
        for(const auto& stage : m_stages)
        {
            if(!stage.cleared())
                return false;
        }
        return true;
    }
};