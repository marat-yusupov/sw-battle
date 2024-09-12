#pragma once

#include <memory>
#include <utility>
#include <vector>
#include <chrono>

#include <BL/Models/Action/BaseAction.hpp>

namespace sw::bl::models::unit
{
    struct BaseUnit
    {
        int id;
        int hp;
        std::pair<int, int> position;
        std::chrono::steady_clock::time_point timestamp;

        BaseUnit(int id, int hp, std::pair<int, int> const &position);

        virtual ~BaseUnit() = default;
    };

    using List = std::vector<std::shared_ptr<unit::BaseUnit>>;
}
