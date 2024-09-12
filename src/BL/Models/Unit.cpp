#include <cmath>
#include <algorithm>

#include <BL/Models/Action.hpp>
#include <BL/Models/Unit.hpp>

namespace sw::bl::models
{
    // Unit
    Unit::Unit(int id, int hp, Position const &position)
        : id{id}, hp{hp}, position{position}
    {
    }

    void Unit::start(UnitList &units, Map const &map)
    {
        Move(units, position, map).start();
    }

    UnitList Unit::lookAround(UnitList &units, std::pair<int, int> range) const
    {
        UnitList enemiesAround;
        for (auto &unit : units)
        {
            double dx = position.first - unit->position.first;
            double dy = position.second - unit->position.second;

            auto distance = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
            if (distance >= range.first && distance <= range.second)
            {
                enemiesAround.push_back(unit);
            }
        }

        return enemiesAround;
    }

    // Warrior
    Warrior::Warrior(int id, int hp, Position const &position, int strength)
        : Unit{id, hp, position}, strength{strength}
    {
    }

    void Warrior::start(UnitList &units, Map const &map)
    {
        auto enemiesAround = lookAround(units);
        if (!enemiesAround.empty())
        {
            MeleeAttack(enemiesAround, strength).start();
            return;
        }

        Unit::start(units, map);
    }

    // Archer
    Archer::Archer(int id, int hp, Position const &position, int strength, int range, int agility)
        : Unit{id, hp, position}, strength{strength}, range{range}, agility{agility}
    {
    }

    void Archer::start(UnitList &units, Map const &map)
    {
        auto enemiesAroundInRange = lookAround(units, {2, range});
        if (!enemiesAroundInRange.empty())
        {
            RangeAttack(enemiesAroundInRange, range, agility).start();
            return;
        }

        auto enemiesInCellRange = lookAround(units);
        if (!enemiesInCellRange.empty())
        {
            MeleeAttack(enemiesInCellRange, strength);
            return;
        }

        Unit::start(units, map);
    }
}