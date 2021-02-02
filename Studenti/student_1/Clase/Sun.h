#pragma once
#include "Resource.h"

namespace GameMechanics
{
	class Sun :
		public Resource
	{
	public:
		Sun(int, int);
		~Sun();

		std::string serialize() override;
	};
}