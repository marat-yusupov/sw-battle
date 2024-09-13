#include <vector>

#include <BL/ForwardDeclaration.hpp>

namespace sw::bl
{
    class Simulator
    {
    private:
        Simulator() = default;

    public:
        static Simulator &instance();

        void run(commands::CommandList const &commands);
    };
}