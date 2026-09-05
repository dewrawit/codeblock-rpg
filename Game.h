#pragma once
#include <string_view>

class Player;
class GameState;
class Enemy;
class CodeBlockPool;

namespace Game
{
    using SV = std::string_view;

    Player createBasePlayer();
    int stageSelect(const GameState& gameState);
    bool playStage(GameState& gameState);
    bool enterBattle(Context& context);
    void playerEditIDEPhase(Player& player, CodeBlockPool& codeBlockPool);
    void runCodePhase(Context& context);
}