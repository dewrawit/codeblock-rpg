#include "Player.h"
#include "CodeBlocks/CodeBlock.h"
#include "Game.h"
#include "CharacterData.h"
#include "Context.h"
int main()
{
    Player player { Game::createCharacter("Player", Data::PlayerHp, Data::PlayerAtk) };
    Player pythonChan { Game::createCharacter("Python-Chan", Data::PythonHp, Data::PythonAtk) };

    Context context { player, pythonChan };
    
    player.showStats();

    return 0;
}