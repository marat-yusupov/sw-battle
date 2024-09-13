#include <algorithm>
#include <memory>
#include <sstream>

#include <IO/System/EventLog.hpp>
#include <IO/Events/MapCreated.hpp>
#include <IO/Events/UnitSpawned.hpp>
#include <IO/Events/MarchStarted.hpp>

#include <BL/Commands/Command.hpp>
#include <BL/Resources/Map.hpp>
#include <BL/Models/Unit.hpp>

namespace sw::bl::commands
{
    Command::Command(std::vector<int> const &params)
        : _params{params}
    {
    }

    // CreateMap
    CreateMap::CreateMap(std::vector<int> const &params)
        : Command(params)
    {
        if (params.size() != 2)
            throw std::runtime_error{"Error: Invalid number of arguments for command \"CreateMap\""};
    }

    void CreateMap::execute(int tick)
    {
        int width = _params[0];
        int height = _params[1];

        resources::Map::instance().initialize(width, height);
        EventLog::instance()
            .log(tick, sw::io::MapCreated{width, height});
    }

    // SpawnArcher
    SpawnArcher::SpawnArcher(std::vector<int> const &params)
        : Command(params)
    {
        if (params.size() != 7)
            throw std::runtime_error{"Error: Invalid number of arguments for command \"SpawnArcher\""};
    }

    void SpawnArcher::execute(int tick)
    {
        auto id = _params[0];
        auto x = _params[1];
        auto y = _params[2];
        auto hp = _params[3];
        auto agility = _params[4];
        auto strength = _params[5];
        auto range = _params[6];

        auto archer = std::make_shared<models::Archer>(id,
                                                       hp,
                                                       std::make_pair(x, y),
                                                       strength,
                                                       range,
                                                       agility);

        resources::Map::instance().addUnit(archer);
        EventLog::instance()
            .log(tick, sw::io::UnitSpawned{id, "Archer", x, y});
    }

    // SpawnWarrior
    SpawnWarrior::SpawnWarrior(std::vector<int> const &params)
        : Command(params)
    {
        if (params.size() != 5)
            throw std::runtime_error{"Error: Invalid number of arguments for command \"SpawnWarrior\""};
    }

    void SpawnWarrior::execute(int tick)
    {
        auto id = _params[0];
        auto x = _params[1];
        auto y = _params[2];
        auto hp = _params[3];
        auto agility = _params[4];

        auto warrior = std::make_shared<models::Warrior>(id,
                                                         hp,
                                                         std::make_pair(x, y),
                                                         agility);

        resources::Map::instance().addUnit(warrior);
        EventLog::instance()
            .log(tick, sw::io::UnitSpawned{id, "Warrior", x, y});
    }

    // March
    March::March(std::vector<int> const &params)
        : Command(params)
    {
        if (params.size() != 3)
            throw std::runtime_error{"Error: Invalid number of arguments for command \"March\""};
    }

    void March::execute(int tick)
    {
        auto unitId = _params[0];
        auto x = _params[1];
        auto y = _params[2];

        auto units = resources::Map::instance().units();
        auto it = std::find_if(units.begin(), units.end(), [unitId](models::UnitPtr const &unit)
                               { return unit->id == unitId; });

        if (it == units.end())
        {
            std::ostringstream oss;
            oss << "Error: Unit with id = \"" << unitId << "\" does not exist!";
            throw std::runtime_error{oss.str()};
        }

        auto const &unit = it->get();
        unit->targetPosition = std::make_pair(x, y);
        EventLog::instance()
            .log(tick, sw::io::MarchStarted{unitId, unit->position.first, unit->position.second, x, y});
    }
}
