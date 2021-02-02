#pragma once
#include "Zombie.h"

namespace GameMechanics
{
	class Buckethead :
		virtual public Zombie
	{
	public:
		Buckethead(int, int);
		~Buckethead();

		std::string serialize() override;
	};
}
