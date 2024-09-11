#include <BL/Models/BaseUnit/Base/BaseUnit.hpp>

namespace sw::bl::models::unit
{
    class Warrior : public BaseUnit
    {
    private:
        int _strength;

    public:
        Warrior(int id, Type type, std::pair<int, int> const &position,
                int hp,
                int strength);
    };
}