#pragma once

#include <map>

#include <BL/Models/ForwardDeclaration.hpp>

namespace sw::bl::resources
{
    class Map
    {
    private:
        int _width{};
        int _height{};
        bool _isInitialize = false;
        models::UnitList _units;

    private:
        Map() = default;

    public:
        static Map &instance();

        void initialize(int width, int height);

        void addUnit(models::UnitPtr const &unit);

        void deleteUnit(models::UnitPtr const &unit);

        models::UnitList units() const;
    };
}
