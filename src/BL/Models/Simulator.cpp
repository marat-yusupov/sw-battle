#include <fstream>
#include <functional>

#include <IO/System/EventLog.hpp>
#include <IO/System/CommandParser.hpp>
#include <IO/System/PrintDebug.hpp>
#include <IO/Commands/CreateMap.hpp>
#include <IO/Commands/SpawnWarrior.hpp>
#include <IO/Commands/SpawnArcher.hpp>
#include <IO/Commands/March.hpp>
#include <IO/Events/MapCreated.hpp>
#include <IO/Events/UnitSpawned.hpp>
#include <IO/Events/MarchStarted.hpp>

#include <BL/Models/Simulator.hpp>
#include <BL/Models/Unit/BaseUnit.hpp>
#include <BL/Models/Unit/Archer.hpp>
#include <BL/Models/Unit/Warrior.hpp>
#include <BL/Models/Action/BaseAction.hpp>
#include <BL/Models/Action/Move.hpp>

namespace sw::bl::models
{
    Simulator::Simulator()
    {
    }

    void Simulator::init(int tick, std::ifstream &file)
    {
        io::CommandParser parser;
        parser.add<io::CreateMap>([this, tick](io::CreateMap command)
                                  { createMap(tick, command); })
            .add<io::SpawnWarrior>([this, tick](io::SpawnWarrior command)
                                   { spawnWarrior(tick, command); })
            .add<io::SpawnArcher>([this, tick](io::SpawnArcher command)
                                  { spawnArcher(tick, command); })
            .add<io::March>([this, tick](io::March command)
                            { march(tick, command); });

        parser.parse(file);
    }

    void Simulator::createMap(int tick, io::CreateMap command)
    {
        _map.width = command.width;
        _map.height = command.height;

        EventLog::instance().log(tick, io::MapCreated(_map.width, _map.height));
    }

    void Simulator::spawnWarrior(int tick, io::SpawnWarrior command)
    {
        auto warrior = std::make_shared<unit::Warrior>(command.unitId,
                                                       command.hp,
                                                       std::make_pair<int, int>(command.x, command.y),
                                                       command.strength);

        _units.push_back(warrior);
        EventLog::instance().log(tick, io::UnitSpawned(warrior->id, "Warrior", warrior->position.first, warrior->position.second));
    }

    void Simulator::spawnArcher(int tick, io::SpawnArcher command)
    {
        auto archer = std::make_shared<unit::Archer>(command.unitId,
                                                     command.hp,
                                                     std::make_pair<int, int>(command.x, command.y),
                                                     command.strength,
                                                     command.range,
                                                     command.agility);

        _units.push_back(archer);
        EventLog::instance().log(tick, io::UnitSpawned(archer->id, "Archer", archer->position.first, archer->position.second));
    }

    void Simulator::march(int tick, io::March command)
    {
        auto march = std::make_shared<action::Move>(command.unitId,
                                                    std::make_pair<int, int>(command.targetX,
                                                                             command.targetY));
        _marches.push_back(march);

        auto unitId = march->unitId;
        auto it = std::find_if(_units.begin(), _units.end(), [&unitId](auto iterable_unit)
                               { return iterable_unit->id == unitId; });
        if (it == _units.end())
        {
            std::ostringstream oss;
            oss << "Error: Command \"" << command.Name << "\" failed, unit with id = " << unitId << " does not exist";
            throw std::runtime_error{oss.str()};
        }

        auto unit = it->get();
        EventLog::instance().log(tick, io::MarchStarted(unit->id,
                                                        unit->position.first,
                                                        unit->position.second,
                                                        command.targetX,
                                                        command.targetY));
    }

    Simulator &Simulator::instance()
    {
        static Simulator instance;
        return instance;
    }

    void Simulator::start(std::ifstream &file)
    {
        for (int tick = 1;; tick++)
        {
            if (tick == 1)
            {
                init(tick, file);
            }

            if (_units.size() < 2)
            {
                return;
            }
        }
    }
}
