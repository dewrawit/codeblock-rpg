#pragma once
#include <string>
#include <string_view>
#include <cassert>

class Character
{
    public:
    enum class GuardType { normal, parry, counter };
    private:
    using SV = std::string_view;

    std::string m_name{};
    int m_hp{};
    int m_atk{};
    GuardType m_guardType{};
    bool m_guarded{ false };

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
    bool isGuarding() const { return m_guarded; }
    int calculateDamageTaken(int baseAtk, Character& attacker) {  

        if(!isGuarding())
        {
            return baseAtk;
        }

        switch(m_guardType)
        {
            case GuardType::normal: return baseAtk / 2; 
            case GuardType::parry: return 0;
            case GuardType::counter: 
                assert(!attacker.isGuarding() && "Attacker shouldn't have guard if it attacks");
                attacker.m_hp -= baseAtk;
                return 0;
            default: assert(false && "Invalid guard type");
        }
    }

    //Fight Component
    void attack(Character& target)
    {
        std::println("{} Attacks!", m_name);

        target.m_hp -= target.calculateDamageTaken(getAtk(), *this);
    }
    void heavyAttack(Character& target)
    {
        std::println("{} Attacks really hard!", m_name);

        target.m_hp -= target.calculateDamageTaken(2 * getAtk(), *this);
    }
    void heal(int amount)
    {
        std::println("{} heals!", m_name);

        assert(m_hp > 0 && "Cannot heal, aleady dead");
        m_hp += amount;
    }
    void guard()
    {
        std::println("{} Guards!", m_name);
        m_guarded = true;
        m_guardType = GuardType::normal;
    }
    void superGuard()
    {
        std::println("{} Super Guards!", m_name);

        m_guarded = true;
        m_guardType = GuardType::parry;
    }
    void counter()
    {
        std::println("{} Set up a counter!", m_name);

        m_guarded = true;
        m_guardType = GuardType::counter;
    }
    void resetGuard()
    {
        m_guarded = false;
    }
};