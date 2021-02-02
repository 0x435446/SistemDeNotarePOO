#pragma once

#include "Projectile.h"

namespace GameMechanics
{
	class Pea :
		public Projectile
	{
	public:
		Pea(int, int);
		~Pea();

		std::string serialize() override;
	};
}
