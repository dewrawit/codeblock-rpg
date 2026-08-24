#include "Player.h"
#include "CodeBlocks/CodeBlock.h"
#include "Game.h"

int main()
{
    Player player { Game::createPlayer() };

    player.showStats();

    return 0;
}