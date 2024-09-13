#pragma once

#include <iostream>
#include <typeindex>
#include <unordered_map>

#include <IO/System/details/PrintFieldVisitor.hpp>

namespace sw
{
	class EventLog
	{
	private:
		EventLog() = default;

	public:
		static EventLog &instance()
		{
			static EventLog instance;
			return instance;
		}

		template <class TEvent>
		void log(int tick, TEvent &&event)
		{
			std::cout << "[" << tick << "] " << TEvent::Name << " ";
			PrintFieldVisitor visitor(std::cout);
			event.visit(visitor);
			std::cout << std::endl;
		}
	};
}