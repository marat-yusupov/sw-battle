#include <algorithm>

#include <BL/Simulator.hpp>
#include <BL/Models/Unit.hpp>
#include <BL/Commands/Command.hpp>
#include <BL/Resources/Map.hpp>

namespace sw::bl
{
    Simulator &Simulator::instance()
    {
        static Simulator instance;
        return instance;
    }

    void Simulator::run(commands::CommandList const &commands)
    {
        int tick = 1;

        for (auto const &command : commands)
        {
            command->execute(tick);
        }

        for (tick = 2;; tick++)
        {
            auto const &map = resources::Map::instance();
            auto units = map.units();

            if (units.size() < 2)
            {
                break;
            }

            bool allActionsDone = true;
            for (auto &unit : units)
            {
                bool actionResult = unit->start(tick, map);
                if (!actionResult)
                {
                    allActionsDone = actionResult;
                }
            }

            if (allActionsDone)
            {
                break;
            }
        }
    }
}
