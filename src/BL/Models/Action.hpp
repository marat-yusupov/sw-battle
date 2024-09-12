#include <BL/Models/ForwardDeclaration.hpp>

namespace sw::bl::models
{
    class Action
    {
    public:
        virtual void start() = 0;
    };

    class Move : public Action
    {
    private:
        UnitList &_units;
        Position &_positionOfMovedUnit;
        Map const &_map;

    public:
        Move(UnitList &units, Position &positionOfMovedUnit, Map const &map);

        void start() override;
    };

    class MeleeAttack : public Action
    {
    private:
        UnitList _targets;
        int _strength;

    public:
        MeleeAttack(UnitList const &_targets, int strength);

        void start() override;
    };

    class RangeAttack : public Action
    {
    private:
        UnitList _targets;
        int _range;
        int _agility;

    public:
        RangeAttack(UnitList const &_targets, int range, int agility);

        void start() override;
    };
}
