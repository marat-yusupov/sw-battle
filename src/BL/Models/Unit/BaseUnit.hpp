#include <utility>
#include <vector>
#include <chrono>

#include <BL/Models/BaseAction.hpp>

namespace sw::bl::models::unit
{
    enum Type
    {
        Warrior,
        Archer
    };

    class BaseUnit
    {
        using ActionList = std::vector<std::shared_ptr<sw::bl::models::BaseAction>>;

    public:
        int _id;
        Type _type;
        std::pair<int, int> _position;
        int _hp;
        ActionList _actions;
        std::chrono::steady_clock::time_point _timestamp;

    public:
        BaseUnit(int id, Type type, std::pair<int, int> const &position, int hp)
            : _id{id}, _type{type}, _position{position}, _hp{hp}
        {
        }

        virtual ~BaseUnit() = default;

        virtual void executeActions() = 0;
    };
}
