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
    void playStage(const GameState& gameState)
    {
        std::println("\n------------------------------------------\n");
        
        std::println("Playing: Stage Start Theme.\n");

        std::println("Entering {} Stage", gameState.getContext().getStage().getBoss().getName());

        //TBD: Make Context connect to stage instead. can Restore stage if player quit stage

    }
}