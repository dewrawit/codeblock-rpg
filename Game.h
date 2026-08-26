#pragma once
#include <string_view>

class Player;
class GameState;

namespace Game
{
    using SV = std::string_view;

    Player createCharacter(SV name, int hp, int atk);
    int stageSelect(const GameState& gameState);
    void playStage(const GameState& gameState);
}