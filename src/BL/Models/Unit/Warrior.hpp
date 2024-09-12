#include <BL/Models/Unit/BaseUnit.hpp>

namespace sw::bl::models::unit
{
    class Warrior : public BaseUnit
    {
    private:
        int _strength;

    public:
        Warrior(int id, int hp, std::pair<int, int> const &position,
                int strength);
    };
}