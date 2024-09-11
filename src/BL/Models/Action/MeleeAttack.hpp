#include <BL/Models/Action/BaseAction.hpp>

namespace sw::bl::models::action
{
    class MeleeAttack : public BaseAction
    {
    private:
        constexpr static int Radius = 1;

        int _strength;

    public:
        MeleeAttack(int strength);

        void start(int tick, Map const &map) override;
    };
}
