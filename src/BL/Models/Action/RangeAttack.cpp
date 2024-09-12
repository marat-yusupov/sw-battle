#include <BL/Models/Map.hpp>
#include <BL/Models/Action/RangeAttack.hpp>

namespace sw::bl::models::action
{
    RangeAttack::RangeAttack(int unitId, int agility, int range)
        : BaseAction{unitId}, _agility{agility}, _range{range}
    {
    }

    void RangeAttack::start()
    {
        // no implementation
    }
}
