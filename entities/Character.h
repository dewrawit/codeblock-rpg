#pragma once
#include <string>
#include <string_view>

class Character
{
    private:
    using SV = std::string_view;

    std::string m_name{};
    int m_hp{};
    int m_atk{};

    public:
    constexpr Character() = default;
    constexpr Character(SV name, int hp, int atk)
        : m_name{ name }
        , m_hp{ hp }
        , m_atk{ atk }
    { }

    const std::string& getName() const { return m_name; }
    int getHp() const { return m_hp; }
    int getAtk() const { return m_atk; }
    bool isAlive() const { return m_hp > 0; }
    bool isDead() const { return !isAlive(); }

    //Fight Component
    void attack(Character& target)
    {
        target.m_hp -= getAtk();
    }



};