#include "GameState.h"
#include "Game.h"
#include "Context.h"
#include "CharacterData.h"

//must also be non const because moving player (changing owner) also counts as modify
GameState::GameState(Player& player) 
    : m_player{ std::move(player) } //must move because player owns unique_ptr
    , m_context{ m_player }
{
    //Make enemies
    m_enemies.push_back(
        Game::createCharacter("Python-Chan", Data::PythonHp, Data::PythonAtk)
    );
    m_enemies.push_back(
        Game::createCharacter("C-Chan", Data::CHp, Data::CAtk)
    );
    m_enemies.push_back(
        Game::createCharacter("Cpp-Chan", Data::CppHp, Data::CppAtk)
    );

} 