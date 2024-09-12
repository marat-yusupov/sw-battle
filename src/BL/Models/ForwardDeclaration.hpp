#include <optional>
#include <memory>
#include <vector>

namespace sw::bl::models
{
    struct Unit;
    using UnitPtr = std::shared_ptr<Unit>;
    using UnitList = std::vector<UnitPtr>;

    class Action;

    struct Map;
    using Position = std::pair<int, int>;
}