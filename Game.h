#pragma once

class Player;
class GameState;

namespace Game
{
    using SV = std::string_view;

    Player createCharacter(SV name, int hp, int atk);
    void stageSelect(const GameState& gameState);
}