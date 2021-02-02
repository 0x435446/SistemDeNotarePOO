#pragma once
#include "Graphics.h"

namespace GameMechanics
{
	class Tile :
		public Graphics
	{
	public:
		Tile(int, int);
		~Tile();
	};
}
