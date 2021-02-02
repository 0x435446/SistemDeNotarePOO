#pragma once
#include "Plant.h"

namespace GameMechanics
{
	class CherryBomb :
		public Plant
	{
	public:
		CherryBomb(int, int);
		~CherryBomb();

		std::string serialize() override;
	};
}
