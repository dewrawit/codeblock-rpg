#pragma once
#include <string_view>

class Player;
class GameState;

namespace Game
{
    using SV = std::string_view;

    Player createBasePlayer();
    int stageSelect(const GameState& gameState);
    void playStage(const GameState& gameState);
}