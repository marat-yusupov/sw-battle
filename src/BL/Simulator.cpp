#include <BL/Simulator.hpp>
#include <BL/Models/Unit.hpp>
#include <BL/Commands/Command.hpp>
#include <BL/Resources/Map.hpp>

#include <iostream>

namespace sw::bl
{
    Simulator &Simulator::instance()
    {
        static Simulator instance;
        return instance;
    }

    void Simulator::run(commands::CommandList const &commands)
    {
        for (int tick = 1;; tick++)
        {
            if (tick == 1)
            {
                for (auto const &command : commands)
                {
                    command->execute(tick);
                }
                continue;
            }

            auto const &map = resources::Map::instance();
            auto units = map.units();

            if (units.size() < 2)
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
