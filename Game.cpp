#include "entities/Player.h"
#include "entities/Enemy.h"
#include "Game.h"
#include "GameState.h"
#include "Utils.h"
#include <string_view>
#include <print>
#include <format>
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
            //Player& player { gameState.getContext().getPlayer() };
            //Enemy& enemy { gameState.getContext().getStage().getCurrentEnemy() };

            if(enterBattle(gameState.getContext()) == win)
            {
                stage.popEnemyFromQueue();
            }
            else
            {
                assert(false && "TBD! Player lose (maybe a life system like megaman later)");
            }
        }
    }
    bool enterBattle(Context& context)
    {        
        context.resetTurnAndActionNumber();

        Player& player { context.getPlayer() };
        Enemy& enemy { context.getActiveEnemy() };

        //Clear any old vector content, resize so its size same as actionPerTurn of enemy
        player.clearAndResizeIDE(static_cast<std::size_t>(enemy.getActionPerTurn()));

        CodeBlockPool codeBlockPool (static_cast<std::size_t>(3 * enemy.getActionPerTurn()));

        //Test if it successfully get all blocks from Database
        //codeBlockPool.printAllBlocks();
        //std::println();

        std::println("Engaging {}!", enemy.getName());

        while(player.isAlive() && enemy.isAlive()) //For each turn
        {
            std::println(">>Turn {}<<", context.getTurnNumber());
            //Every New turn
            context.resetActionNumber();
            player.clearIDE();
            codeBlockPool.fillRandomBlocks();
            codeBlockPool.shufflePool();

            //TBD
            //make sure the generation algorithm gave at least x block in each block type
            //(Number/Var, Fight action, operator etc.) 
            
            playerEditIDEPhase(player, codeBlockPool);
            
            runCodePhase(context);

            context.incrementTurn();
        }
        assert(false && "Just testing");
        return player.isAlive();
    }
    void playerEditIDEPhase(Player& player, CodeBlockPool& codeBlockPool)
    {
        using ST = std::size_t;

        constexpr int quitOrCancel { -1 };
        //TBD, gave player option to stop editing

        bool cont { true };
        while(cont)
        {
            player.printIDE();
            codeBlockPool.printPool();

            int rowIndex { 
                Utils::getInt("Select Row Number (0 to RUN): ", 0, 
                    static_cast<int>(player.getIDE().size())) - 1
            };

            if(rowIndex == quitOrCancel)
                break;

            int blockIndex { 
                Utils::getInt("Select Block Number (0 to cancel): ", 0, 
                    static_cast<int>(codeBlockPool.getPoolSize())) - 1
            };

            if(blockIndex == quitOrCancel)
                return;

            //unique_ptr is an exception when move: 
            //the old owner guaranteed to be nullptr, we're safe.
            auto& targetIDEBlock { player.getIDE()[static_cast<ST>(rowIndex)] };
            auto& selectedPoolBlock { codeBlockPool[static_cast<ST>(blockIndex)] };

            if(targetIDEBlock == nullptr)
            {
                targetIDEBlock = std::move(selectedPoolBlock);
                codeBlockPool.removeBlockAtIndex(static_cast<ST>(blockIndex));
            } 
            else //aready occupied, replace that row with new block and return it back to pool
            {
                std::swap(targetIDEBlock, selectedPoolBlock);
            }
        }
    }
    void runCodePhase(Context& context)
    {
        Player& player { context.getPlayer() };
        Enemy& enemy { context.getActiveEnemy() };

        context.resetActionNumber();

        for(auto i {0uz}; i < player.getIDE().size(); ++i)
        {
            std::println("Running Code Line: {}", i + 1);

            context.incrementActionNumber();

            //Player do thier shit
            player.getIDE()[i]->run(context);
            enemy.resetGuard(); //Guard will only last for next action

            //if enemy dies, return
            if(enemy.isDead() || player.isDead())
                return;

            //Enemy do thier shit
            enemy.takeTurn(context);
            player.resetGuard();

            //if player dies, return
            if(enemy.isDead() || player.isDead())
                return;
        }
    }
}