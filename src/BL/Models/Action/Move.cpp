#include <BL/Models/Map.hpp>
#include <BL/Models/Action/Move.hpp>

namespace sw::bl::models::action
{
    Move::Move(int unitId, std::pair<int, int> const &targetPoint)
        : BaseAction{unitId}, _targetPoint{targetPoint}
    {
    }

    void Move::start()
    {
        // no implementation
    }
}
