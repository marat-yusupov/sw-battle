#include <BL/Models/Action/BaseAction.hpp>
#include <BL/Models/Unit/Warrior.hpp>

namespace sw::bl::models::unit
{
    Warrior::Warrior(int id, int hp, std::pair<int, int> const &position, int strength)
        : BaseUnit(id, hp, position), _strength{strength}
    {
    }
}