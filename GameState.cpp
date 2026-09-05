#include "GameState.h"
#include "Game.h"
#include "Context.h"
#include "entities/EnemyDatabase.h"
#include "stages/StageDatabase.h"
#include "keys/Key.h"
#include <cassert>

//must also be non const because moving player (changing owner) also counts as modify
GameState::GameState(Player& player) 
    : m_enemyDatabase{}
    , m_stageDatabase{ m_enemyDatabase }
    , m_player{ std::move(player) } //must move because player owns unique_ptr
    , m_context{ m_player }
{
    using ST = std::size_t;

    //Already created in this order in the class
    //EnemyDatabase enemyDatabase {};
    //StageDatabase stageDatabase { enemyDatabase };

    //All stages in the game
    m_stages.resize(static_cast<ST>(StageIndex::maxStages));

    m_stages[static_cast<ST>(StageIndex::python)] 
    = m_stageDatabase.createStage(Key::Stage::Python);

    // m_stages[static_cast<ST>(StageIndex::c)]
    // = m_stageDatabase.createStage(Key::Stage::C);

    // m_stages[static_cast<ST>(StageIndex::cpp)]
    // = m_stageDatabase.createStage(Key::Stage::Cpp);
} 
void GameState::setupStageContext(int select)
{
    assert(select >= 1 && static_cast<std::size_t>(select) <= m_stages.size() 
    && "Select out of bounds");

    std::size_t stageIndex { static_cast<std::size_t>(select - 1) };

    m_context.setStage(m_stages[stageIndex]);
}
void GameState::restoreStage(StageIndex stageIndex)
{
    using ST = std::size_t;

    //Grab a fresh new stage from the database
    switch(stageIndex)
    {
        case StageIndex::python: 
            m_stages[static_cast<ST>(StageIndex::python)] 
            = m_stageDatabase.createStage(Key::Stage::Python);
            break;
        // case StageIndex::c:
        //     m_stages[static_cast<ST>(StageIndex::c)]
        //     = m_stageDatabase.createStage(Key::Stage::C);
        //     break;
        // case StageIndex::cpp:
        //     m_stages[static_cast<ST>(StageIndex::cpp)]
        //     = m_stageDatabase.createStage(Key::Stage::Cpp);
        //     break;
        default:
            assert(false && "Restore stage received invalid stage index.");
    }
}