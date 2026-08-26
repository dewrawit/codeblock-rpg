#include "Player.h"
#include "Game.h"
#include "GameState.h"
#include "Utils.h"
#include <string_view>
#include <print>

namespace Game
{
    using SV = std::string_view;

    Player createCharacter(SV name, int hp, int atk)
    {        
        return Player{ name, hp, atk };
    }
    int stageSelect(const GameState& gameState)
    {
        std::println("Playing: Stage Select Theme.\n");

        int iteration { 1 };
        for(const auto& bot : gameState.getEnemiesVector())
        {
            std::println("{}. {}", iteration, bot.getName());
            ++iteration;
        }

        return Utils::getInt(
            "Pick Stage Number > ", 1, static_cast<int>(gameState.getEnemiesVector().size())
        );
    }
    void playStage(const GameState& gameState)
    {
        std::println("\n------------------------------------------\n");
        
        std::println("Playing: Stage Start Theme.\n");

        std::println("Entering {} Stage", gameState.getContext().getOpponent().getName());

    }
}