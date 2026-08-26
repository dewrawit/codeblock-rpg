#include "Player.h"
#include "CodeBlocks/CodeBlock.h"
#include "Game.h"
#include "CharacterData.h"
#include "Context.h"
#include "GameState.h"

int main()
{
    Player player { Game::createCharacter("Player", Data::PlayerHp, Data::PlayerAtk) };

    GameState gameState { player }; //player is moved into gameState, not copied
    //player.showStats(); undefined behvaior, player lost ownership (mine doesnt print name)

    while(true)
    {
        int select { Game::stageSelect(gameState) };

        gameState.setupStageContext(select);
        
        Game::playStage(gameState);
        
        //temp
        int a;
        std::cin >> a;
    }

    return 0; 
}