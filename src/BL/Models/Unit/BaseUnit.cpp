#include <BL/Models/Unit/BaseUnit.hpp>

namespace sw::bl::models::unit
{
    BaseUnit::BaseUnit(int id, Type type, std::pair<int, int> const &position, int hp)
        : _id{id}, _type{type}, _position{position}, _hp{hp}
    {
    }
}