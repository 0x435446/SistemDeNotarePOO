#pragma once
#include "Plant.h"

namespace GameMechanics
{
	class Sunflower :
		public Plant
	{
	public:
		Sunflower(int ,int);
		~Sunflower();

		std::string serialize() override;
	};
}
