#include "Utils.h"

namespace Utils
{
    using SV = std::string_view;
    int getInt(SV prompt, int min, int max)
    {
        while(true)
        {
            std::print("{}",prompt);

            int input{};
            std::cin >> input;

            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            if(std::cin.gcount() > 1)
            {
                continue;
            }

            if(input >= min && input <= max)
            {
                return input;
            }
        }
    }
}