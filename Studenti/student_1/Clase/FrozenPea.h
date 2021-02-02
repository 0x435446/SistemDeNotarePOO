#pragma once
#include "Projectile.h"

namespace GameMechanics
{
	class FrozenPea :
		public Projectile
	{
	public:
		FrozenPea(int, int);
		~FrozenPea();

		std::string serialize() override;
	};
}
