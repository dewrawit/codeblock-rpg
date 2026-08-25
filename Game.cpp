#include "Player.h"
#include "Game.h"
#include <string_view>

namespace Game
{
    using SV = std::string_view;

    Player createCharacter(SV name, int hp, int atk)
    {
        return Player{ name, hp, atk };
    }
}