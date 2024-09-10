#include <BL/Models/BaseUnit/Archer.hpp>

namespace sw::bl::models::unit
{
    Archer::Archer(int id, Type type, std::pair<int, int> const &position,
                   int hp,
                   int strength,
                   int range,
                   int agility)
        : BaseUnit(id, type, position, hp), _strength{strength}, _range{range}, _agility{agility}
    {
    }

    void Archer::executeActions()
    {
        // no implementation
    }
}
