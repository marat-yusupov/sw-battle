#include <BL/Models/Action/BaseAction.hpp>

namespace sw::bl::models::action
{
    class RangeAttack : public BaseAction
    {
    private:
        constexpr static int Radius = 2;

        int _agility;
        int _range;

    public:
        RangeAttack(int agility, int range);

        void start(Map const &map) override;
    };
}