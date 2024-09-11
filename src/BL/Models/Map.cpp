#include <algorithm>

#include <BL/Models/Map.hpp>

namespace sw::bl::models
{
    Map::Map(int width, int height)
        : _width{width}, _height{height}
    {
    }

    const Map::UnitList &Map::unitList() const
    {
        return _unitList;
    }

    void Map::addUnit(std::shared_ptr<unit::BaseUnit> const &unit)
    {

        bool is_taken_position = std::any_of(_unitList.begin(), _unitList.end(), [&](auto const &iterated_unit)
                                             { return iterated_unit->position == unit->position; });

        if (is_taken_position)
        {
            return;
        }

        _unitList.push_back(unit);
    }

    void Map::deleteUnit(std::shared_ptr<unit::BaseUnit> const &unit)
    {
        auto it = std::find(_unitList.begin(), _unitList.end(), unit);
        if (it == _unitList.end())
        {
            return;
        }

        _unitList.erase(it);
    }
}
