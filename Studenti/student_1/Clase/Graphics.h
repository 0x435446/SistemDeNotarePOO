#pragma once
#include "Entity.h"

namespace GameMechanics
{
	class Graphics :
		public Entity
	{
	public:
		Graphics(int, int);
		~Graphics();
	};
}
