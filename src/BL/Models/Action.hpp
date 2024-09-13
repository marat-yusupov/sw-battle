#include <BL/Models/ForwardDeclaration.hpp>

namespace sw::bl::models
{
    class Action
    {
    public:
        virtual void start(int tick) = 0;
    };

    class Move : public Action
    {
    private:
        UnitPtr _movedUnit;
        OptPosition &_targetPosition;

    private:
        int calculateAxisStep(int targetCoordinate, int currentCoordinate) const;

    public:
        Move(UnitPtr const &movedUnit,
             OptPosition &targetPosition);

        void start(int tick) override;
    };

    class Attack : public Action
    {
    protected:
        UnitPtr attacker;

        virtual UnitPtr selectTarget(UnitList const &targets);

    public:
        Attack(UnitPtr const &attacker);
    };

    class MeleeAttack : public Attack
    {
    private:
        UnitList _targets;
        int _strength;

    public:
        MeleeAttack(UnitPtr const &attacker, UnitList const &_targets, int strength);

        void start(int tick) override;
    };

    class RangeAttack : public Attack
    {
    private:
        UnitList _targets;
        int _range;
        int _agility;

    private:
        UnitPtr selectTarget(UnitList const &targets) override;

    public:
        RangeAttack(UnitPtr const &attacker, UnitList const &_targets, int range, int agility);

        void start(int tick) override;
    };
}
