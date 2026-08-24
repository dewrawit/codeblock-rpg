#include "Player.h"
#include "Game.h"

namespace Game
{
    Player createPlayer()
    {
        constexpr int playerHp { 100 };
        constexpr int playerAtk { 10 };

        return Player{ "Player", playerHp, playerAtk };
    }
}