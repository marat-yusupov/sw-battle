#pragma once

#include <iosfwd>

namespace sw::io
{
	struct SpawnArcher
	{
		constexpr static const char *Name = "SPAWN_ARCHER";

		int unitId{};
		int x{};
		int y{};
		int hp{};
		int agility{};
		int strength{};
		int range{};

		template <typename Visitor>
		void visit(Visitor &visitor)
		{
			visitor.visit("unitId", unitId);
			visitor.visit("x", x);
			visitor.visit("y", y);
			visitor.visit("hp", hp);
			visitor.visit("agility", agility);
			visitor.visit("strength", strength);
			visitor.visit("range", range);
		}
	};
}