namespace sw::io
{
	struct MarchEnded
	{
		constexpr static const char *Name = "MARCH_ENDED";

		int unitId{};
		int x{};
		int y{};

		template <typename Visitor>
		void visit(Visitor &visitor)
		{
			visitor.visit("unitId", unitId);
			visitor.visit("x", x);
			visitor.visit("y", y);
		}
	};
}