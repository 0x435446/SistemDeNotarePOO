#pragma once
#include "IDamageable.h"

namespace GameMechanics
{
	class Damageable :
		public IDamageable
	{
	protected:
		int HP;

	public:
		Damageable();
		~Damageable();

		void receiveDamage(int) override;
		int getRemainingHP() override;
	};
}
