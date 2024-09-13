#include <cmath>
#include <algorithm>

#include <IO/Events/UnitMoved.hpp>
#include <IO/Events/UnitAttacked.hpp>
#include <IO/Events/UnitDied.hpp>
#include <IO/Events/MarchEnded.hpp>
#include <IO/System/EventLog.hpp>

#include <BL/Models/Action.hpp>
#include <BL/Models/Unit.hpp>

namespace sw::bl::models
{
    // Move
    int Move::calculateAxisStep(int targetCoordinate, int currentCoordinate) const
    {
        constexpr static int STEP_FORWARD = 1;
        constexpr static int STEP_BACK = -1;
        constexpr static int DONT_MOVE = 0;

        int direction = targetCoordinate - currentCoordinate;

        if (direction > 0)
        {
            return STEP_FORWARD;
        }

        if (direction == 0)
        {
            return DONT_MOVE;
        }

        return STEP_BACK;
    }

    Move::Move(UnitPtr const &movedUnit,
               OptPosition &targetPosition)
        : _movedUnit{movedUnit}, _targetPosition{targetPosition}
    {
    }

    void Move::start(int tick)
    {
        if (!_targetPosition)
        {
            return;
        }

        _movedUnit->position.first += calculateAxisStep(_targetPosition->first, _movedUnit->position.first);
        _movedUnit->position.second += calculateAxisStep(_targetPosition->second, _movedUnit->position.second);

        EventLog::instance().log(tick, io::UnitMoved(_movedUnit->id,
                                                     _movedUnit->position.first,
                                                     _movedUnit->position.second));

        if (_targetPosition == _movedUnit->position)
        {
            _targetPosition = std::nullopt;
            EventLog::instance().log(tick, io::MarchEnded(_movedUnit->id,
                                                          _movedUnit->position.first,
                                                          _movedUnit->position.second));
        }
    }

    // Attack
    UnitPtr Attack::selectTarget(UnitList const &targets)
    {
        // clang-format off
        auto iteratorOnTarget = std::min_element(
            targets.begin(), targets.end(), [](UnitPtr const& lhs, UnitPtr const& rhs) {
                if (lhs->hp != rhs->hp) {
                    return lhs->hp < rhs->hp;
                }
                
                return lhs->id < rhs->id;
            }
        );
        // clang-format on

        return *iteratorOnTarget;
    }

    Attack::Attack(UnitPtr const &attacker)
        : attacker{attacker}
    {
    }

    // MeleeAttack
    MeleeAttack::MeleeAttack(UnitPtr const &attacker, UnitList const &targets, int strength)
        : Attack{attacker}, _targets{targets}, _strength{strength}
    {
    }

    void MeleeAttack::start(int tick)
    {
        auto target = selectTarget(_targets);
        target->hp -= _strength;

        EventLog::instance().log(tick, io::UnitAttacked(attacker->id,
                                                        target->id,
                                                        _strength,
                                                        target->hp < 0
                                                            ? 0
                                                            : target->hp));

        if (target->hp <= 0)
        {
            resources::Map::instance().deleteUnit(target);
            EventLog::instance().log(tick, io::UnitDied(target->id));
        }
    }

    // RangeAttack
    UnitPtr RangeAttack::selectTarget(UnitList const &targets)
    {
        // clang-format off
        auto iteratorOnTarget = std::min_element(
            targets.begin(), targets.end(), [this](UnitPtr const& lhs, UnitPtr const& rhs) {
                auto distance = [](Position const& p1, Position const& p2) {
                    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
                };

                double dist_lhs = distance(lhs->position, attacker->position);
                double dist_rhs = distance(rhs->position, attacker->position);
                
                if (dist_lhs != dist_rhs) {
                    return dist_lhs < dist_rhs;
                }

                if (lhs->hp != rhs->hp) {
                    return lhs->hp < rhs->hp;
                }
                
                return lhs->id < rhs->id;
            }
        );
        // clang-format on

        return *iteratorOnTarget;
    }

    RangeAttack::RangeAttack(UnitPtr const &attacker, UnitList const &targets, int range, int agility)
        : Attack{attacker}, _targets{targets}, _range{range}, _agility{agility}
    {
    }

    void RangeAttack::start(int tick)
    {
        auto target = selectTarget(_targets);
        target->hp -= _agility;

        EventLog::instance().log(tick, io::UnitAttacked(attacker->id,
                                                        target->id,
                                                        _agility,
                                                        target->hp < 0
                                                            ? 0
                                                            : target->hp));

        if (target->hp <= 0)
        {
            resources::Map::instance().deleteUnit(target);
            EventLog::instance().log(tick, io::UnitDied(target->id));
        }
    }
}