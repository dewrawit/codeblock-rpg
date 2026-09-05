#include "entities/Player.h"
#include "codeBlocks/CodeBlock.h"
#include "Game.h"
#include "Context.h"
#include "GameState.h"

int main()
{
    Player player { Game::createBasePlayer() };

    GameState gameState { player }; //player is moved into gameState, not copied
    //player.showStats(); undefined behvaior, player lost ownership (mine doesnt print name)

    constexpr bool lose { false };

    std::println("-------------------------------------------------------------------");
    std::println("Note: This is a prototype version of my planned Godot game "
        "so some features is not added / simplified to demonstrate just the game mechanic");
    std::println("-------------------------------------------------------------------");

    while(true)
    {
        int select { Game::stageSelect(gameState) };

        gameState.setupStageContext(select);
        
        if( Game::playStage(gameState) == lose )
        {
            gameState.restoreStage(static_cast<GameState::StageIndex>(select - 1));
        }

        if(gameState.gameWon())
        {
            std::println("You win! Thanks for playing the prototype, see you in Godot.");
            std::println("(If I don't burnout)");
            break;
        }
    }

    return 0; 
}