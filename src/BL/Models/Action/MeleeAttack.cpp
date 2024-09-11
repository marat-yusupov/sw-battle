#include <BL/Models/Map.hpp>
#include <BL/Models/Action/MeleeAttack.hpp>

namespace sw::bl::models::action
{
    MeleeAttack::MeleeAttack(int strength)
        : BaseAction{Name::MeleeAttack}, _strength{strength}
    {
    }

    void MeleeAttack::start(int tick, Map const &map)
    {
        // no implementation
    }
}