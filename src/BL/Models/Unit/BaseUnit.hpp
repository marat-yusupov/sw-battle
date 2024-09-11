#include <utility>
#include <vector>
#include <chrono>

#include <BL/Models/BaseAction.hpp>

namespace sw::bl::models::unit
{
    enum Type
    {
        Warrior,
        Archer
    };

    struct BaseUnit
    {
        int id;
        Type type;
        std::pair<int, int> position;
        int hp;
        std::chrono::steady_clock::time_point timestamp;

        BaseUnit(int id, Type type, std::pair<int, int> const &position, int hp);

        virtual ~BaseUnit() = default;
    };
}
