#include <optional>
#include <memory>
#include <vector>

namespace sw::bl::models
{
    struct Unit;
    using UnitPtr = std::shared_ptr<Unit>;
    using UnitList = std::vector<UnitPtr>;

    class Action;
    using ActionList = std::vector<std::shared_ptr<Action>>;

    using Position = std::pair<int, int>;
    using OptPosition = std::optional<Position>;
}