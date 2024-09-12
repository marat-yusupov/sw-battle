#include <chrono>

#include <BL/Models/Unit/BaseUnit.hpp>

namespace sw::bl::models::unit
{
    BaseUnit::BaseUnit(int id, int hp, std::pair<int, int> const &position)
        : id{id}, hp{hp}, position{position}, timestamp{std::chrono::steady_clock::now()}
    {
    }
}