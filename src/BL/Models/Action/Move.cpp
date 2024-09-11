#include <BL/Models/Map.hpp>
#include <BL/Models/Action/Move.hpp>

namespace sw::bl::models::action
{
    Move::Move(std::pair<int, int> const &targetPoint)
        : BaseAction{Name::Move}, _targetPoint{targetPoint}
    {
    }

    void Move::start(int tick, Map const &map)
    {
        // no implementation
    }
}
