#pragma once
#include "Enemy.h"
#include "EnemyInfo.h"
#include <unordered_map>

class EnemyDatabase
{
    private:
    std::unordered_map<std::string,Enemy> m_enemyDatabase{};

    public:
    EnemyDatabase()
    {
        m_enemyDatabase.emplace(
            "Python-Chan", 
            Enemy{

                EnemyInfo{
                    .name = "Python-Chan",
                    .hp = 200,
                    .atk = 20,
                    .actionPerTurn = 5,
                },

                [](Enemy& self) -> void
                {
                    for(int i {0}; i < self.getActionPerTurn(); ++i)
                    {
                        
                    }
                }
                
            }
        );
    }


};