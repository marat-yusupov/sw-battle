#include <BL/Models/BaseAction/BaseAction.hpp>
#include <BL/Models/BaseUnit/Warrior.hpp>

namespace sw::bl::models::unit
{
    Warrior::Warrior(int id, Type type, std::pair<int, int> const &position, int hp, int strength)
        : BaseUnit(id, type, position, hp), _strength{strength}
    {
    }
}