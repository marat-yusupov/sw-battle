#pragma once

#include <iosfwd>

namespace sw::io
{
	struct March
	{
		constexpr static const char *Name = "MARCH";

		int unitId{};
		int targetX{};
		int targetY{};

		template <typename Visitor>
		void visit(Visitor &visitor)
		{
			visitor.visit("unitId", unitId);
			visitor.visit("targetX", targetX);
			visitor.visit("targetY", targetY);
		}
	};
}