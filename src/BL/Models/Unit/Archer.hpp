#include <BL/Models/Unit/BaseUnit.hpp>

namespace sw::bl::models::unit
{
    class Archer : public BaseUnit
    {
    private:
        int _strength;
        int _range;
        int _agility;

    public:
        Archer(int id, int hp, std::pair<int, int> const &position,
               int strength,
               int range,
               int agility);
    };
}
