#include "entities/Player.h"
#include "entities/Enemy.h"
#include "Game.h"
#include "GameState.h"
#include "Utils.h"
#include <string_view>
#include <print>
#include "codeBlocks/CodeBlockPool.h"
#include "codeBlocks/CodeBlock.h"

namespace Game
{
    using SV = std::string_view;

    Player createBasePlayer()
    {        
        constexpr SV playerName { "Player" };
        constexpr int playerHp { 100 };
        constexpr int playerAtk { 10 };
        return Player{ playerName, playerHp, playerAtk };
    }
    int stageSelect(const GameState& gameState)
    {
        std::println("Playing: Stage Select Theme.\n");

        int iteration { 1 };
        for(const auto& stage : gameState.getStageVector())
        {
            std::println("{}. {}", iteration, stage.getBoss().getName());
            ++iteration;
        }

        return Utils::getInt(
            "Pick Stage Number > ", 1, static_cast<int>(gameState.getStageVector().size())
        );
    }
    void playStage(GameState& gameState)
    {
        std::println("------------------------------------------\n");

        std::println("Entering {} Stage", gameState.getContext().getStage().getBoss().getName());

        std::println("\n------------------------------------------\n");

        constexpr bool win { true };

        Stage& stage { gameState.getContext().getStage() };
  
        while(!stage.cleared())
        {
            Player& player { gameState.getContext().getPlayer() };
            Enemy& enemy { gameState.getContext().getStage().getCurrentEnemy() };

            if(enterBattle(player, enemy) == win)
            {
                stage.popEnemyFromQueue();
            }
            else
            {
                assert(false && "TBD! Player lose (maybe a life system like megaman later)");
            }
        }
    }
    bool enterBattle(Player& player, Enemy& enemy)
    {        

        //Clear any old vector content, resize so its size same as actionPerTurn of enemy
        player.clearAndResizeIDE(static_cast<std::size_t>(enemy.getActionPerTurn()));

        CodeBlockPool codeBlockPool (static_cast<std::size_t>(3 * enemy.getActionPerTurn()));

        //Test if it successfully get all blocks from Database
        codeBlockPool.printAllBlocks();
        std::println();

        while(player.isAlive() && enemy.isAlive()) //For each turn
        {
            player.clearIDE();

            //1.Generate blocks from code block pool, lets say 3*actionPerTurn blocks
            //But make sure the generation algorithm gave at least x block in each block type
            //(Number/Var, Fight action, operator etc.) 

            codeBlockPool.fillRandomBlocks();
            codeBlockPool.printPool();

            //2.Input to ask what block they want and where to put it in
            //This will modify the codeBlock vector of the player
            //Check if that line is occupied / able to insert a block there or not
            //Keep going until player run code
            
            //3.When player is ready, type 'R' to start the run
            //For each line, player act the code first, follow by enemy (preset behavior)

            assert(false && "Just testing");
        }
        return player.isAlive();
    }
}