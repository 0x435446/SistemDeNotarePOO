#pragma once
#include "Peashooter.h"

namespace GameMechanics
{
	class SnowPea :
		public Peashooter
	{
	public:
		SnowPea(int, int);
		~SnowPea();

		std::string serialize() override;
	};
}

