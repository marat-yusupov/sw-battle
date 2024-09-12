#include <BL/Models/Action.hpp>
#include <BL/Models/Unit.hpp>

namespace sw::bl::models
{
    // Move
    Move::Move(UnitList &units, Position &positionOfMovedUnit, Map const &map)
        : _units{units}, _positionOfMovedUnit{positionOfMovedUnit}, _map{map}
    {
    }

    void Move::start()
    {
    }

    // MeleeAttack
    MeleeAttack::MeleeAttack(UnitList const &targets, int strength)
        : _targets{targets}, _strength{strength}
    {
    }

    void MeleeAttack::start()
    {
    }

    // RangeAttack
    RangeAttack::RangeAttack(UnitList const &targets, int range, int agility)
        : _targets{targets}, _range{range}, _agility{agility}
    {
    }

    void RangeAttack::start()
    {
    }
}