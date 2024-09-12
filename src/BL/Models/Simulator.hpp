#include <memory>
#include <fstream>

#include <BL/Models/Map.hpp>
#include <BL/Models/Unit/BaseUnit.hpp>
#include <BL/Models/Action/BaseAction.hpp>

namespace sw::bl::models
{
    class Simulator
    {
    private:
        Map _map;
        unit::List _units;
        action::List _marches;

    private:
        Simulator();

        void init(int tick, std::ifstream &file);

        void createMap(int tick, io::CreateMap command);

        void spawnWarrior(int tick, io::SpawnWarrior command);

        void spawnArcher(int tick, io::SpawnArcher command);

        void march(int tick, io::March command);

    public:
        static Simulator &instance();

        void start(std::ifstream &file);
    };
}
