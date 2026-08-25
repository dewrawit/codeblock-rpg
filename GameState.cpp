#include "GameState.h"
#include "Game.h"
#include "Context.h"
#include "CharacterData.h"

GameState::GameState(const Player& player)
{
    //Make enemies
    m_enemies.push_back(Game::createCharacter("Python-Chan", Data::PythonHp, Data::PythonAtk));

} 