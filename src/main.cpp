#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include <IO/System/CommandParser.hpp>
#include <IO/System/PrintDebug.hpp>
#include <IO/Commands/CreateMap.hpp>
#include <IO/Commands/SpawnWarrior.hpp>
#include <IO/Commands/SpawnArcher.hpp>
#include <IO/Commands/March.hpp>
#include <IO/System/EventLog.hpp>
#include <IO/Events/MapCreated.hpp>
#include <IO/Events/UnitSpawned.hpp>
#include <IO/Events/MarchStarted.hpp>
#include <IO/Events/MarchEnded.hpp>
#include <IO/Events/UnitMoved.hpp>
#include <IO/Events/UnitDied.hpp>
#include <IO/Events/UnitAttacked.hpp>

#include <BL/Simulator.hpp>
#include <BL/ForwardDeclaration.hpp>
#include <BL/Commands/Command.hpp>

using namespace sw;

bl::commands::CommandList parseArgs(std::ifstream &file)
{
	bl::commands::CommandList result;

	io::CommandParser parser;
	parser.add<io::CreateMap>(
			  [&result](auto command)
			  {
				  std::vector<int> params{command.width, command.height};
				  auto createMap = std::make_shared<bl::commands::CreateMap>(params);
				  result.push_back(createMap);
			  })
		.add<io::SpawnWarrior>(
			[&result](auto command)
			{
				std::vector<int> params{command.unitId, command.x, command.y, command.hp, command.strength};
				auto spawnWarrior = std::make_shared<bl::commands::SpawnWarrior>(params);
				result.push_back(spawnWarrior);
			})
		.add<io::SpawnArcher>(
			[&result](auto command)
			{
				std::vector<int> params{command.unitId,
										command.x,
										command.y,
										command.hp,
										command.agility,
										command.strength,
										command.range};
				auto spawnArcher = std::make_shared<bl::commands::SpawnArcher>(params);
				result.push_back(spawnArcher);
			})
		.add<io::March>(
			[&result](auto command)
			{
				std::vector<int> params{command.unitId, command.targetX, command.targetY};
				auto march = std::make_shared<bl::commands::March>(params);
				result.push_back(march);
			});

	parser.parse(file);

	return result;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		throw std::runtime_error("Error: No file specified in command line argument");
	}

	std::ifstream file(argv[1]);
	if (!file)
	{
		throw std::runtime_error("Error: File not found - " + std::string(argv[1]));
	}

	auto commands = parseArgs(file);
	bl::Simulator::instance().run(commands);

	return 0;
}
