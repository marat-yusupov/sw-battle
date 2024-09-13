#pragma once

#include <iosfwd>

namespace sw::io
{
	struct SpawnWarrior
	{
		constexpr static const char *Name = "SPAWN_WARRIOR";

		int unitId{};
		int x{};
		int y{};
		int hp{};
		int strength{};

		template <typename Visitor>
		void visit(Visitor &visitor)
		{
			visitor.visit("unitId", unitId);
			visitor.visit("x", x);
			visitor.visit("y", y);
			visitor.visit("hp", hp);
			visitor.visit("strength", strength);
		}
	};
}