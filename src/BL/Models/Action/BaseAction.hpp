#pragma once

#include <memory>
#include <vector>

namespace sw::bl::models
{
    // forward declaration
    class Map;

    namespace action
    {

        class BaseAction
        {
        public:
            int unitId;

        public:
            BaseAction(int unitId)
                : unitId{unitId}
            {
            }

            virtual ~BaseAction() = default;

            virtual void start() = 0;
        };

        using List = std::vector<std::shared_ptr<BaseAction>>;
    }
}
