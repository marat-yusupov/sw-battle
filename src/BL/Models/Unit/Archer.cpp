#include <BL/Models/Unit/Archer.hpp>

namespace sw::bl::models::unit
{
    Archer::Archer(int id, int hp, std::pair<int, int> const &position,
                   int strength,
                   int range,
                   int agility)
        : BaseUnit(id, hp, position), _strength{strength}, _range{range}, _agility{agility}
    {
    }
}
