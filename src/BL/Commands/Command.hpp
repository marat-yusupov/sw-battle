#include <map>
#include <string>
#include <vector>

namespace sw::bl::commands
{
    class Command
    {
    protected:
        std::vector<int> _params;

    public:
        Command(std::vector<int> const &params);

        virtual ~Command() = default;

        virtual void execute(int tick) = 0;
    };

    class CreateMap : public Command
    {
    public:
        CreateMap(std::vector<int> const &params);

        void execute(int tick) override;
    };

    class SpawnArcher : public Command
    {
    public:
        SpawnArcher(std::vector<int> const &params);

        void execute(int tick) override;
    };

    class SpawnWarrior : public Command
    {
    public:
        SpawnWarrior(std::vector<int> const &params);

        void execute(int tick) override;
    };

    class March : public Command
    {
    public:
        March(std::vector<int> const &params);

        void execute(int tick) override;
    };
}