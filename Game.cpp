#include "Player.h"
#include "Game.h"
#include "GameState.h"
#include <string_view>
#include <print>

namespace Game
{
    using SV = std::string_view;

    Player createCharacter(SV name, int hp, int atk)
    {        
        return Player{ name, hp, atk };
    }
    void stageSelect(const GameState& gameState)
    {
        std::println("Playing: Stage Select Theme.");
        for(const auto& bot : gameState.getEnemiesVector())
        {
            bot.showStats();
        }
    }
}