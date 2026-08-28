#pragma once
#include <string_view>

namespace Key
{
    using SV = std::string_view;

    namespace Enemy
    {
        constexpr SV PythonChan {"Python-Chan"};
        constexpr SV BlueSnake {"Blue-Snake"};
        constexpr SV YellowSnake {"Yellow-Snake"};
        constexpr SV PyAConda {"Py-Aconda"};

        
        constexpr SV CChan {"C-Chan"};

    }
    namespace Stage
    {
        constexpr SV Python {"Python-Stage"};

        constexpr SV C {"C-Stage"};

        constexpr SV Cpp {"Cpp-Stage"};
    }
}