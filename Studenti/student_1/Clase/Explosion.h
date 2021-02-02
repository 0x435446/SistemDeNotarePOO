#pragma once
#include "Projectile.h"

namespace GameMechanics
{
	class Explosion :
		public Projectile
	{
	public:
		Explosion(int, int);
		~Explosion();

		std::string serialize() override;
	};
}
