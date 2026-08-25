#pragma once

class Player;

namespace Game
{
    using SV = std::string_view;

    Player createCharacter(SV name, int hp, int atk);
}