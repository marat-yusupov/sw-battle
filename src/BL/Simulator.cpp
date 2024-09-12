#include <BL/Simulator.hpp>

#include <IO/System/CommandParser.hpp>
#include <IO/System/PrintDebug.hpp>
#include <IO/Commands/CreateMap.hpp>
#include <IO/Commands/SpawnWarrior.hpp>
#include <IO/Commands/SpawnArcher.hpp>
#include <IO/Commands/March.hpp>

namespace sw::bl
{
    void Simulator::run()
    {
        io::CommandParser parser;
        parser.add<io::CreateMap>(
                  [](auto command)
                  {
                      printDebug(std::cout, command);
                  })
            .add<io::SpawnWarrior>(
                [](auto command)
                {
                    printDebug(std::cout, command);
                })
            .add<io::SpawnArcher>(
                [](auto command)
                {
                    printDebug(std::cout, command);
                })
            .add<io::March>(
                [](auto command)
                {
                    printDebug(std::cout, command);
                });
    }
}
