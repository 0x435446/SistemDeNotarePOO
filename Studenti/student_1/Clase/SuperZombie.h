#pragma once
#include "Buckethead.h"
#include "Polevaulting.h"

namespace GameMechanics
{
	class SuperZombie :
		public Buckethead, public Polevaulting
	{
	public:
		SuperZombie(int, int);
		~SuperZombie();

		std::string serialize() override;
	};
}
