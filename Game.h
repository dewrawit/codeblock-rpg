#pragma once
#include <string_view>

class Player;
class GameState;
class Enemy;

namespace Game
{
    using SV = std::string_view;

    Player createBasePlayer();
    int stageSelect(const GameState& gameState);
    void playStage(GameState& gameState);
    bool enterBattle(Player& player, Enemy& enemy);
}