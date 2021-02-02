#pragma once
#include "Entity.h"
#include "Damageable.h"

namespace GameMechanics
{
	class Plant :
		public Entity, public Damageable
	{
	protected:
		int cost;
		int shootRate;
		EntityID projectileType;

	public:
		Plant(int, int);
		~Plant();

		EntityID shoot();
		int getShootRate();
	};
}
