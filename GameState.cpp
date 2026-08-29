#include "GameState.h"
#include "Game.h"
#include "Context.h"
#include "entities/EnemyDatabase.h"
#include "stages/StageDatabase.h"
#include "keys/Key.h"
#include <cassert>

//must also be non const because moving player (changing owner) also counts as modify
GameState::GameState(Player& player) 
    : m_player{ std::move(player) } //must move because player owns unique_ptr
    , m_context{ m_player }
{
    EnemyDatabase enemyDatabase {};
    StageDatabase stageDatabase { enemyDatabase };

    //All stages in the game
    m_stages.push_back(stageDatabase.createStage(Key::Stage::Python));
    m_stages.push_back(stageDatabase.createStage(Key::Stage::C));
    m_stages.push_back(stageDatabase.createStage(Key::Stage::Cpp));
} 
void GameState::setupStageContext(int select)
{
    assert(select >= 1 && static_cast<std::size_t>(select) <= m_stages.size() 
    && "Select out of bounds");

    std::size_t stageIndex { static_cast<std::size_t>(select - 1) };

    m_context.setStage(m_stages[stageIndex]);
}