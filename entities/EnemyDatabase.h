#pragma once
#include "Enemy.h"
#include "EnemyInfo.h"
#include "../keys/Key.h"
#include <unordered_map>
#include <string_view>
#include <cassert>

class EnemyDatabase
{
    private:
    using SV = std::string_view;

    static inline std::unordered_map<SV,Enemy> m_enemyDatabase{};

    public:

    Enemy createEnemy(SV key) const { //Make an enemy copy to prevent modifying database

        assert(m_enemyDatabase.contains(key) && "createEnemy key is not in EnemyDatabase");
        
        return m_enemyDatabase.at(key); 
    } 

    EnemyDatabase()
    {
        //Python-Chan
        m_enemyDatabase.emplace(
            Key::Enemy::PythonChan, 
            Enemy{
                EnemyInfo{
                    .name = std::string {Key::Enemy::PythonChan},
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

        m_enemyDatabase.emplace(
            Key::Enemy::BlueSnake, 
            Enemy{

                EnemyInfo{
                    .name = std::string {Key::Enemy::BlueSnake},
                    .hp = 100,
                    .atk = 10,
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

        m_enemyDatabase.emplace(
            Key::Enemy::YellowSnake, 
            Enemy{

                EnemyInfo{
                    .name = std::string {Key::Enemy::YellowSnake},
                    .hp = 100,
                    .atk = 10,
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

        m_enemyDatabase.emplace(
            Key::Enemy::PyAConda, 
            Enemy{

                EnemyInfo{
                    .name = std::string {Key::Enemy::PyAConda},
                    .hp = 100,
                    .atk = 10,
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