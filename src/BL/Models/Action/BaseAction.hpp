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
            MeleeAttack,
            RangeAttack,
        };

        class BaseAction
        {
        private:
            Name _name;

        public:
            BaseAction(Name name)
                : _name{name}
            {
            }

            virtual ~BaseAction() = default;

            Name name() const
            {
                return _name;
            }

            virtual void start(Map const &map) = 0;
        };
    }
}
