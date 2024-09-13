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
    Move::Move(UnitPtr const &movedUnit,
               Position const &targetPosition)
        : _movedUnit{movedUnit}, _targetPosition{targetPosition}
    {
    }

    void Move::start(int tick)
    {
        // TODO: предусмотреть, что могут быть занятые другими юнитами клетки
        if (_targetPosition == _movedUnit->position)
        {
            EventLog::instance().log(tick, io::MarchEnded(_movedUnit->id,
                                                          _movedUnit->position.first,
                                                          _movedUnit->position.second));
            return;
        }

        int dx = _targetPosition.first - _movedUnit->position.first;
        int dy = _targetPosition.second - _movedUnit->position.second;

        _movedUnit->position.first += dx > 0 ? 1 : (dx == 0 ? 0 : -1);
        _movedUnit->position.second += dy > 0 ? 1 : (dy == 0 ? 0 : -1);

        EventLog::instance().log(tick, io::UnitMoved(_movedUnit->id,
                                                     _movedUnit->position.first,
                                                     _movedUnit->position.second));
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

        if (target->hp <= 0)
        {
            resources::Map::instance().deleteUnit(target);
            EventLog::instance().log(tick, io::UnitDied(target->id));
            return;
        }

        EventLog::instance().log(tick, io::UnitAttacked(attacker->id,
                                                        target->id,
                                                        _strength,
                                                        target->hp));
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

                // TODO: дублирование... не хорошо, надо бы почистить
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

        if (target->hp <= 0)
        {
            resources::Map::instance().deleteUnit(target);
            EventLog::instance().log(tick, io::UnitDied(target->id));
            return;
        }

        EventLog::instance().log(tick, io::UnitAttacked(attacker->id,
                                                        target->id,
                                                        _agility,
                                                        target->hp));
    }
}