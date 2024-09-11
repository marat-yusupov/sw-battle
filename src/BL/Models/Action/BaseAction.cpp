#include <BL/Models/Action/BaseAction.hpp>

namespace sw::bl::models::action
{
    BaseAction::BaseAction(Name name)
        : _name{name}
    {
    }

    Name BaseAction::name() const
    {
        return _name;
    }
}