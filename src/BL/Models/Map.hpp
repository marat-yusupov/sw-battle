#pragma once

#include <cstdint>

namespace sw::bl::models
{
    struct Map
    {
        uint32_t width{};
        uint32_t height{};

        Map(uint32_t width = 0, uint32_t height = 0);
    };
}
