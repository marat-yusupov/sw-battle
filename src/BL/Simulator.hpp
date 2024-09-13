#include <vector>

#include <BL/ForwardDeclaration.hpp>

namespace sw::bl
{
    class Simulator
    {
    private:
        Simulator() = default;

        bool isAllMarchesIsEnded(models::UnitList const &units);

    public:
        static Simulator &instance();

        void run(commands::CommandList const &commands);
    };
}