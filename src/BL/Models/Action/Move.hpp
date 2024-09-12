#include <BL/Models/Action/BaseAction.hpp>

namespace sw::bl::models::action
{
    class Move : public BaseAction
    {
    private:
        std::pair<int, int> _targetPoint;

    public:
        Move(int unitId, std::pair<int, int> const &targetPoint);

        void start() override;
    };
}
