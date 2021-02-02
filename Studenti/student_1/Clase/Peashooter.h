#pragma once

#include "Plant.h"

namespace GameMechanics
{
	class Projectile;

	class Peashooter :
		public Plant
	{
	public:
		Peashooter(int, int);
		~Peashooter();

		std::string serialize() override;
	};
}