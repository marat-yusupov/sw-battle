#include <BL/Models/Map.hpp>
#include <BL/Models/Action/MeleeAttack.hpp>

namespace sw::bl::models::action
{
    MeleeAttack::MeleeAttack(int unitId, int strength)
        : BaseAction{unitId}, _strength{strength}
    {
    }

    void MeleeAttack::start()
    {
        // no implementation
    }
}