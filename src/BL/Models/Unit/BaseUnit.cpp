#include <BL/Models/Unit/BaseUnit.hpp>

namespace sw::bl::models::unit
{
    BaseUnit::BaseUnit(int id, Type type, std::pair<int, int> const &position, int hp)
        : id{id}, type{type}, position{position}, hp{hp}
    {
    }
}