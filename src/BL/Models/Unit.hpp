#include <list>

#include <BL/Models/ForwardDeclaration.hpp>

namespace sw::bl::models
{
    struct Unit
    {
        int id;
        int hp;
        Position position;

        Unit(int id, int hp, Position const &position);

        virtual ~Unit() = default;

        virtual void start(UnitList &units, Map const &map);

        UnitList lookAround(UnitList &units, std::pair<int, int> range = {0, 1}) const;
    };

    struct Warrior : public Unit
    {
        int strength;

        Warrior(int id, int hp, Position const &position, int strength);

        void start(UnitList &units, Map const &map) override;
    };

    struct Archer : public Unit
    {
        int strength;
        int range;
        int agility;

        Archer(int id, int hp, Position const &position, int strength, int range, int agility);

        void start(UnitList &units, Map const &map) override;
    };
}
