#include <iostream>
#include <fstream>

#include <IO/System/CommandParser.hpp>
#include <IO/System/PrintDebug.hpp>
#include <IO/Commands/CreateMap.hpp>
#include <IO/Commands/SpawnWarrior.hpp>
#include <IO/Commands/SpawnArcher.hpp>
#include <IO/Commands/March.hpp>

#include <BL/Models/Map.hpp>
#include <BL/Models/Simulator.hpp>
#include <BL/Models/Unit/BaseUnit.hpp>
#include <BL/Models/Unit/Warrior.hpp>
#include <BL/Models/Unit/Archer.hpp>
#include <BL/Models/Action/BaseAction.hpp>
#include <BL/Models/Action/Move.hpp>

using namespace sw;

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

	bl::models::Simulator::instance().start(file);

	return 0;
}
