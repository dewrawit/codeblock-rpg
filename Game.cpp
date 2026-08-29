#include "entities/Player.h"
#include "Game.h"
#include "GameState.h"
#include "Utils.h"
#include <string_view>
#include <print>

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
        std::println("\n------------------------------------------\n");
        
        std::println("Playing: Stage Start Theme.\n");

        std::println("Entering {} Stage", gameState.getContext().getStage().getBoss().getName());

        constexpr bool win { true };

        Stage& stage { gameState.getContext().getStage() };
  
        while(!stage.cleared())
        {
            Player& player { gameState.getContext().getPlayer() };
            Enemy& enemy { gameState.getContext().getStage().getNextEnemy() };

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
        //Where the code block shit happens
        
    }
}