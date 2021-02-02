#pragma once

#include <string>

namespace GameMechanics
{
	class Peashooter;

	class ISerializable
	{
	public:
		ISerializable();
		~ISerializable();

		virtual std::string serialize() = 0;
		
	};
}
