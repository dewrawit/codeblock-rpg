#pragma once
#include "entities/Enemy.h"
#include <queue>

class Stage
{
    private:
    std::queue<Enemy> m_enemies{};   
    
    public:
    Stage()
    {

    }
};