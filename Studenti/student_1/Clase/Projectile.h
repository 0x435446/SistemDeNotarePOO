#pragma once
#include "Entity.h"
#include "IDamaging.h"
#include "IMoveable.h"

namespace GameMechanics
{
	class Projectile :
		public Entity, public IMoveable, public IDamaging
	{
	protected:
		EffectInflicted inflictableEffect;

	public:
		Projectile(int, int);
		~Projectile();

		void move() override;
		EffectInflicted getEffect();
	};
}
