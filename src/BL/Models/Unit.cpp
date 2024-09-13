#include <cmath>
#include <algorithm>

#include <BL/Models/Action.hpp>
#include <BL/Models/Unit.hpp>

namespace sw::bl::models
{
    // Unit
    Unit::Unit(int id, int hp, Position const &position, OptPosition const &targetPosition)
        : id{id}, hp{hp}, position{position}, targetPosition{targetPosition}
    {
    }

    void Unit::start(int tick, resources::Map const &map)
    {
        Move(shared_from_this(), targetPosition).start(tick);
    }

    UnitList Unit::lookAround(resources::Map const &map, std::pair<double, double> range) const
    {
        UnitList enemiesAround;
        for (auto &unit : map.units())
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

    void Warrior::start(int tick, resources::Map const &map)
    {
        auto enemiesAround = lookAround(map);
        if (!enemiesAround.empty())
        {
            MeleeAttack(shared_from_this(), enemiesAround, strength).start(tick);
            return;
        }

        Unit::start(tick, map);
    }

    // Archer
    Archer::Archer(int id, int hp, Position const &position, int strength, int range, int agility)
        : Unit{id, hp, position}, strength{strength}, range{range}, agility{agility}
    {
    }

    void Archer::start(int tick, resources::Map const &map)
    {
        auto enemiesAroundInRange = lookAround(map, {2, range});
        if (!enemiesAroundInRange.empty())
        {
            RangeAttack(shared_from_this(), enemiesAroundInRange, range, agility).start(tick);
            return;
        }

        auto enemiesInCellRange = lookAround(map);
        if (!enemiesInCellRange.empty())
        {
            MeleeAttack(shared_from_this(), enemiesInCellRange, strength);
            return;
        }

        Unit::start(tick, map);
    }
}