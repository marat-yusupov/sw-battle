
#include <string>

namespace sw::io
{
	struct UnitDied
	{
		constexpr static const char *Name = "UNIT_DIED";

		int unitId{};

		template <typename Visitor>
		void visit(Visitor &visitor)
		{
			visitor.visit("unitId", unitId);
		}
	};
}