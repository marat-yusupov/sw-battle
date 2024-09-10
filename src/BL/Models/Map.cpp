#include <BL/Models/Map.hpp>

namespace sw::bl::models
{
    Map::Map(int width, int height)
        : _width{width}, _height{height}
    {
    }

    int Map::width() const
    {
        return _width;
    }

    int Map::height() const
    {
        return _height;
    }
}
