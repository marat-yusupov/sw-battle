#include <list>

#include <BL/Models/ForwardDeclaration.hpp>
#include <BL/Resources/Map.hpp>

namespace sw::bl::models
{
    struct Unit : public std::enable_shared_from_this<Unit>
    {
        int id;
        int hp;
        Position position;
        OptPosition targetPosition;

        Unit(int id, int hp, Position const &position, OptPosition const &targetPosition = std::nullopt);

        virtual ~Unit() = default;

        virtual bool start(int tick, resources::Map const &Map);

        UnitList lookAround(resources::Map const &Map, std::pair<double, double> range = {0.5, 1.5}) const;
    };

    struct Warrior : public Unit
    {
        int strength;

        Warrior(int id, int hp, Position const &position, int strength);

        bool start(int tick, resources::Map const &Map) override;
    };

    struct Archer : public Unit
    {
        int strength;
        int range;
        int agility;

        Archer(int id, int hp, Position const &position, int strength, int range, int agility);

        bool start(int tick, resources::Map const &Map) override;
    };
}
