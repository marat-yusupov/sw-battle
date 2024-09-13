#include <algorithm>

#include <BL/Simulator.hpp>
#include <BL/Models/Unit.hpp>
#include <BL/Commands/Command.hpp>
#include <BL/Resources/Map.hpp>

namespace sw::bl
{
    bool Simulator::isAllMarchesIsEnded(models::UnitList const &units)
    {
        // clang-format off
        return std::all_of(units.begin(), units.end(), 
            [](models::UnitPtr const &unit)
                {
                    if(!unit->targetPosition) {
                        return true;
                    }

                    return false; 
                }
            );
        // clang-format on
    }

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

            if (isAllMarchesIsEnded(units))
            {
                break;
            }

            for (auto &unit : units)
            {
                unit->start(tick, map);
            }
        }
    }
}
