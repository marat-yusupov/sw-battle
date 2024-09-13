#include <memory>
#include <vector>

namespace sw::bl::commands
{
    class Command;
    using CommandPtr = std::shared_ptr<Command>;
    using CommandList = std::vector<CommandPtr>;
}