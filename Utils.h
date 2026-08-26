#pragma once
#include <string_view>
#include <print>
#include <limits>
#include <iostream>

namespace Utils
{
    using SV = std::string_view;
    int getInt(SV prompt, int min, int max);
}