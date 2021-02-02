#pragma once

namespace GameMechanics
{
	class IDamageable
	{
	public:
		virtual void receiveDamage(int) = 0;
		virtual int getRemainingHP() = 0;
	};
}
