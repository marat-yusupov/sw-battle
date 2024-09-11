#pragma once

#include <map>
#include <string>

namespace sw::bl::models
{
    // forward declaration
    class Map;

    namespace action
    {
        enum Name
        {
            Move,
            MeleeAttack,
            RangeAttack,
        };

        class BaseAction
        {
        private:
            Name _name;

        public:
            BaseAction(Name name);

            virtual ~BaseAction() = default;

            virtual void start(int tick, Map const &map) = 0;

            Name name() const;
        };
    }
}
