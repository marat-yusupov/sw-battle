#include <algorithm>
#include <sstream>

#include <BL/Resources/Map.hpp>
#include <BL/Models/Unit.hpp>

namespace sw::bl::resources
{
    Map &Map::instance()
    {
        static Map instance;
        return instance;
    }

    void Map::initialize(int width, int height)
    {
        if (_isInitialize)
        {
            return;
        }

        _width = width;
        _height = height;
        _isInitialize = true;
    }

    void Map::addUnit(models::UnitPtr const &unit)
    {
        if (unit->position.first > _width || unit->position.second > _height)
        {
            throw std::runtime_error{"Error: Attempt to place a unit outside the map"};
        }

        _units.push_back(unit);
    }

    void Map::deleteUnit(models::UnitPtr const &unit)
    {
        auto it = std::find(_units.begin(), _units.end(), unit);
        if (it == _units.end())
        {
            std::ostringstream oss;
            oss << "Error: Unit with id = \"" << unit->id << "\" does not exist!";
            throw std::runtime_error{oss.str()};
        }

        _units.erase(it);
    }

    models::UnitList Map::units() const
    {
        return _units;
    }
}
