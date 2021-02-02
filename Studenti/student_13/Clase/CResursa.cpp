#include "CResursa.h"
#define COL_DISTANCE 16


void CResursa::newSun(UserInterface::CField &game)
{
	int ok = 1;
	char** teren = game.getField();
	int place=rand() % 9 + 1;
	while (teren[1][place * COL_DISTANCE + 10] == 'S')
	{
		ok = 1;
		for (int j = 1; j < 10; j++)
			if (teren[1][COL_DISTANCE * j + 10] != 'S')
			{
				ok = 0;
				break;
			}
		place = rand() % 8 + 1;
		if (ok == 1) break;
	}
	//while(teren[1][place*COL_DISTANCE+10]=='S')
	//	place = rand() % 8 + 1;
	game.add_on_field('S', 0, place);
}

void CResursa::collectSun(UserInterface::CField& game, int place)
{
	game.clear_on_field(0, place);
		
}
