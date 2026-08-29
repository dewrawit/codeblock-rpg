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

    static inline std::unordered_map<std::string,Enemy> m_enemyDatabase{};

    public:

    Enemy createEnemy(const std::string& key) const { //Make an enemy copy to prevent modifying database

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
                    .name = Key::Enemy::PythonChan,
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
                    .name = Key::Enemy::BlueSnake,
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
                    .name = Key::Enemy::YellowSnake,
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
                    .name = Key::Enemy::PyAConda,
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

        //C-Chan
        m_enemyDatabase.emplace(
            Key::Enemy::CChan, 
            Enemy{

                EnemyInfo{
                    .name = Key::Enemy::CChan,
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
            Key::Enemy::ArrayPillar,
            Enemy{

                EnemyInfo{
                    .name = Key::Enemy::ArrayPillar,
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
            Key::Enemy::MemLeech,
            Enemy{

                EnemyInfo{
                    .name = Key::Enemy::MemLeech,
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
            Key::Enemy::StarTick,
            Enemy{

                EnemyInfo{
                    .name = Key::Enemy::StarTick,
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
            Key::Enemy::PointBeetle,
            Enemy{

                EnemyInfo{
                    .name = Key::Enemy::PointBeetle,
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

        //Cpp-Chan
        m_enemyDatabase.emplace(
            Key::Enemy::CppChan,
            Enemy{

                EnemyInfo{
                    .name = Key::Enemy::CppChan,
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
            Key::Enemy::SegFlea,
            Enemy{

                EnemyInfo{
                    .name = Key::Enemy::SegFlea,
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
            Key::Enemy::RaiiFly,
            Enemy{

                EnemyInfo{
                    .name = Key::Enemy::RaiiFly,
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
            Key::Enemy::TempTula,
            Enemy{

                EnemyInfo{
                    .name = Key::Enemy::TempTula,
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