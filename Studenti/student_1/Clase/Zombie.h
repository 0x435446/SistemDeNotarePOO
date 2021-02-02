#pragma once
#include "Enemy.h"

namespace GameMechanics
{
	class Zombie :
		public Enemy
	{
	public:
		Zombie(int, int);
		~Zombie();

		bool hasJumped() override;
		void setJumped(bool) override;

		std::string serialize() override;
	};
}
