#pragma once
#include "Entity.h"

namespace GameMechanics
{
	class Resource :
		public Entity
	{
	protected:
		unsigned resourcePoints;

	public:
		Resource(int, int);
		~Resource();

		unsigned collectResources();
	};
}

