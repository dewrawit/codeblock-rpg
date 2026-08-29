#pragma once
#include <string>

namespace Key
{
    using S = std::string;

    namespace Enemy
    {
        constexpr S PythonChan {"Python-Chan"};
        constexpr S BlueSnake {"Blue-Snake"};
        constexpr S YellowSnake {"Yellow-Snake"};
        constexpr S PyAConda {"PyAconda"};

        
        constexpr S CChan {"C-Chan"};
        constexpr S ArrayPillar {"ArrayPillar"};
        constexpr S StarTick {"StarTick"};
        constexpr S PointBeetle {"PointBeetle"};
        constexpr S MemoryLeech {"MemoryLeech"};

        constexpr S CppChan {"Cpp-Chan"};
        constexpr S SegFlea {"SegFlea"};
        constexpr S RaiiFly {"RaiiFly"};
        constexpr S TempTula {"TempTula"};

    }
    namespace Stage
    {
        constexpr S Python {"Python-Stage"};

        constexpr S C {"C-Stage"};

        constexpr S Cpp {"Cpp-Stage"};
    }
}