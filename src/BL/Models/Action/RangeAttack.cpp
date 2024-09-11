#include <BL/Models/Map.hpp>
#include <BL/Models/Action/RangeAttack.hpp>

namespace sw::bl::models::action
{
    RangeAttack::RangeAttack(int agility, int range)
        : BaseAction{Name::RangeAttack}, _agility{agility}, _range{range}
    {
    }

    void RangeAttack::start(int tick, Map const &map)
    {
        // no implementation
    }
}
