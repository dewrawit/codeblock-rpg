#pragma once
#include <string>
#include <functional>

class Enemy;

struct EnemyInfo
{
    std::string name{};
    int hp{};
    int atk{};
    int actionPerTurn{};
    std::function<void(Enemy&)> behavior{};
    bool defeated{ false };
};