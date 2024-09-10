#include <BL/Models/BaseUnit/Base/BaseUnit.hpp>

namespace sw::bl::models::unit
{
    class Archer : public BaseUnit
    {
    private:
        int _strength; // TODO: зачем этому юниту эта характеристика?
        int _range;
        int _agility;

    public:
        Archer(int id, Type type, std::pair<int, int> const &position,
               int hp,
               int strength,
               int range,
               int agility);

        void executeActions() override;
    };
}
