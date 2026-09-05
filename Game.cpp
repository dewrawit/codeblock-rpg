#include "entities/Player.h"
#include "entities/Enemy.h"
#include "Game.h"
#include "GameState.h"
#include "Utils.h"
#include <string_view>
#include <print>
#include <format>
#include <iostream>
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

        while(true)
        {
            int iteration { 1 };
            for(const auto& stage : gameState.getStageVector())
            {
                std::println("{}. {} {}"
                    ,iteration
                    ,stage.getBoss().getName()
                    ,(stage.cleared() ? "( Cleared )" : ""));

                ++iteration;
            }

            int pick { Utils::getInt(
                "Pick Stage Number > ", 1, static_cast<int>(gameState.getStageVector().size()) 
            )};

            int stageIndex { pick - 1 };

            if(gameState.getStageVector()[static_cast<std::size_t>(stageIndex)].cleared())
            {
                std::println("Already cleared this stage.");
            }

            return pick;
        }
        
    }
    bool playStage(GameState& gameState)
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

            gameState.getPlayer().resetToBaseStat();
            
            if(enterBattle(gameState.getContext()) == win)
            {
                std::println("{} Defeated!",stage.getCurrentEnemy().getName());
                stage.popEnemyFromQueue();
            }
            else
            {
                std::println("You died! Level failed!");
                return false;
            }
        }

        std::println("{} Stage Cleared!", stage.getStageKey());
        return true;
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
            context.incrementTurn();

            std::println(">>Turn {}<<", context.getTurnNumber());

            //Every New turn
            context.resetActionNumber();
            player.clearIDE();
            codeBlockPool.clearAndResetPool();
            codeBlockPool.fillRandomBlocks();
            codeBlockPool.shufflePool();

            std::println("Player: {} HP, {} ATK\n Enemy: {} HP, {} ATK", 
                player.getHp(), player.getAtk(), enemy.getHp(), enemy.getAtk());
            
            playerEditIDEPhase(player, codeBlockPool);
            
            runCodePhase(context);
        }
        return player.isAlive();
    }
    void playerEditIDEPhase(Player& player, CodeBlockPool& codeBlockPool)
    {
        using ST = std::size_t;

        constexpr int quitOrCancel { -1 };

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

            //Back to selecting row
            if(blockIndex == quitOrCancel)
                continue;

            

            //unique_ptr is an exception when move: 
            //the old owner guaranteed to be nullptr, we're safe.
            auto& targetIDEBlock { player.getIDE()[static_cast<ST>(rowIndex)] };
            auto& selectedPoolBlock { codeBlockPool[static_cast<ST>(blockIndex)] };

            if(targetIDEBlock == nullptr)
            {
                targetIDEBlock = std::move(selectedPoolBlock);
                codeBlockPool.removeBlockAtIndex(static_cast<ST>(blockIndex));
                //targetIDEBlock gets ownership of the block in the pool
            } 
            else //aready occupied, replace that row with new block and return it back to pool
            {
                std::swap(targetIDEBlock, selectedPoolBlock);
                //targetIDEBlock will now point to the block in the pool we selected
            }

            //Check if it needs arguments
            if(targetIDEBlock->getType() == CodeBlock::Type::oneInt)
            {
                //If fails it will throw bad cast (it shouldn't fail)
                auto& block = dynamic_cast<OneIntBlock&>(*targetIDEBlock);

                int argIndex {
                    Utils::getInt("Select Block Number as argument: ",
                        1, static_cast<int>(codeBlockPool.getPoolSize()) - 1)
                };

                auto& selectedArgBlock { codeBlockPool[static_cast<ST>(argIndex)] };
                block.setArgBlock(selectedArgBlock); 

                //Because after moving, that index becomes nullptr
                codeBlockPool.removeBlockAtIndex(static_cast<ST>(argIndex));               
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
            auto& ideBlock { player.getIDE()[i] };

            if(ideBlock != nullptr)
            {
                //std::cout << *ideBlock << std::endl;
                ideBlock->run(context);
            } 
            else
            {
                std::println("Empty line, action skipped!");
            }
                
            enemy.resetGuard(); //Guard will only last for next action

            if(enemy.isDead() || player.isDead())
                return;

            //Enemy do thier shit
            enemy.takeTurn(context);
            player.resetGuard();

            if(enemy.isDead() || player.isDead())
                return;
        }
    }
}