#pragma once
#include <string>

namespace Key
{
    using S = std::string;

    namespace Enemy
    {
        //Reduce Enemies since this is a prototype demo version
        
        constexpr S PythonChan {"Python Chan"};
        constexpr S BlueSnake {"Blue Snake"};
        // constexpr S YellowSnake {"Yellow Snake"};
        // constexpr S PyAConda {"PyAconda"};

        
        constexpr S CChan {"C Chan"};
        constexpr S ArrayPillar {"ArrayPillar"};
        // constexpr S StarTick {"StarTick"};
        // constexpr S PointBeetle {"PointBeetle"};
        // constexpr S MemLeech {"MemLeech"};

        constexpr S CppChan {"Cpp Chan"};
        constexpr S SegFlea {"SegFlea"};
        // constexpr S RaiiFly {"RaiiFly"};
        // constexpr S TempTula {"TempTula"};

    }
    namespace Stage
    {
        constexpr S Python {"Python-Stage"};

        constexpr S C {"C-Stage"};

        constexpr S Cpp {"Cpp-Stage"};
    }

    namespace Block
    {
        constexpr S Five {"Five"};
        constexpr S Ten {"Ten"};
        constexpr S Fifteen {"Fifteen"};
        constexpr S Twenty {"Twenty"};
        
        constexpr S Attack {"Attack"};
        constexpr S HeavyAttack {"HeavyAttack"};
        constexpr S LifeSteal {"LifeSteal"};
        constexpr S Guard {"Guard"};
        constexpr S Parry {"Parry"};
        constexpr S Counter {"Counter"};
    }
}