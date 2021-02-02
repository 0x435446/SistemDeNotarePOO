#include "Map.h"



Map::Map()
{
}

void Map::drawMap()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	for (int i = 0; i <= MAP_H; i++)
	{
		for (int j = 0; j <= MAP_W; j++)
		{
			if ((j + 0) % 5 == 0 || j == 0)
			{
				std::cout << "|";
			}
			else
			{
				if ((i + 0) % 5 == 0 || i == 0)
				{
					std::cout << "_";
				}
				else
					std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}


Map::~Map()
{
}
