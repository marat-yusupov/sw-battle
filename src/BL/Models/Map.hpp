#include <map>
#include <memory>

#include <BL/Models/Unit/BaseUnit.hpp>

namespace sw::bl::models
{
    class Map
    {
        using UnitList = std::vector<std::shared_ptr<unit::BaseUnit>>;

    private:
        int _width;
        int _height;
        UnitList _unitList;

    public:
        Map(int width, int height);

        const UnitList &unitList() const;

        void addUnit(std::shared_ptr<unit::BaseUnit> const &unit);

        void deleteUnit(std::shared_ptr<unit::BaseUnit> const &unit);
    };
}
