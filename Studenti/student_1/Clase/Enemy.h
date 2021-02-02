#pragma once
#include "Entity.h"
#include "Damageable.h"
#include "IDamaging.h"
#include "IMoveable.h"

namespace GameMechanics
{
	class Enemy :
		public Entity, public IMoveable, public Damageable, public IDamaging
	{
	protected:
		EffectInflicted effect;
		int timeInflicted;
		int points;

	public:
		Enemy(int, int);
		~Enemy();

		void move() override;
		void receiveEffect(EffectInflicted);
		void setTimeInflicted(int);
		int getPoints();

		virtual bool hasJumped() = 0;
		virtual void setJumped(bool) = 0;
	};
}
