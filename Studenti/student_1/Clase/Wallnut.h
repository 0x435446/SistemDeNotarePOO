#pragma once
#include "Plant.h"

namespace GameMechanics
{
	class Wallnut :
		public Plant
	{
	public:
		Wallnut(int, int);
		~Wallnut();

		std::string serialize() override;
	};
}
