#include "Map.h"
#include <Windows.h>
Map *Map::instance = nullptr;

void  Map::doPatrat(int x, int y)
{
	

	conOut(x, y) << (char)colt_stanga_sus;
	//conOut(x, y + 1) << (char)linie_verticala;
	conOut(x, y + 2) << (char)colt_stanga_jos;
	conOut(x + 1, y) << (char)linie_orizontala;
	conOut(x + 2, y) << (char)linie_orizontala;
	conOut(x + 3, y) << (char)linie_orizontala;
	conOut(x + 4, y) << (char)linie_orizontala;
	conOut(x + 5, y) << (char)colt_dreapta_sus;
	//conOut(x+5, y + 1) << (char)linie_verticala;
	conOut(x + 5, y + 2) << (char)colt_dreapta_jos;
	conOut(x + 4, y + 2) << (char)linie_orizontala;
	conOut(x + 3, y + 2) << (char)linie_orizontala;
	conOut(x + 2, y + 2) << (char)linie_orizontala;
	conOut(x + 1, y + 2) << (char)linie_orizontala;

}
void Map:: doPatrat1(int x, int y)
{


	conOut(x, y) << (char)colt_stanga_sus;
	conOut(x, y + 1) << (char)linie_verticala;
	conOut(x, y + 2) << (char)colt_stanga_jos;
	conOut(x + 1, y) << (char)linie_orizontala;
	conOut(x + 2, y) << (char)linie_orizontala;
	conOut(x + 3, y) << (char)linie_orizontala;
	conOut(x + 4, y) << (char)linie_orizontala;
	conOut(x + 5, y) << (char)colt_dreapta_sus;
	conOut(x+5, y + 1) << (char)linie_verticala;
	conOut(x + 5, y + 2) << (char)colt_dreapta_jos;
	conOut(x + 4, y + 2) << (char)linie_orizontala;
	conOut(x + 3, y + 2) << (char)linie_orizontala;
	conOut(x + 2, y + 2) << (char)linie_orizontala;
	conOut(x + 1, y + 2) << (char)linie_orizontala;

}
void Map::doPatrat2(int x, int y)
{


	conOut(x, y) << (char)colt_stanga_sus;
	conOut(x, y + 1) << (char)linie_verticala;
	conOut(x, y + 2) << (char)linie_verticala;
	
	conOut(x, y + 3) << (char)colt_stanga_jos;
	conOut(x + 1, y) << (char)linie_orizontala;
	conOut(x + 2, y) << (char)linie_orizontala;
	conOut(x + 3, y) << (char)linie_orizontala;
	conOut(x + 4, y) << (char)linie_orizontala;
	conOut(x + 5, y) << (char)colt_dreapta_sus;
	conOut(x + 5, y + 1) << (char)linie_verticala;
	conOut(x+5, y + 2) << (char)linie_verticala;
	
	conOut(x + 5, y + 3) << (char)colt_dreapta_jos;
	conOut(x + 4, y + 3) << (char)linie_orizontala;
	conOut(x + 3, y + 3) << (char)linie_orizontala;
	conOut(x + 2, y + 3) << (char)linie_orizontala;
	conOut(x + 1, y + 3) << (char)linie_orizontala;

}
void Map::doHome(int x, int y)
{
	x = x - 2;
	conOut(x, y) << (char)colt_stanga_sus;
	conOut(x+1, y ) << (char)linie_orizontala;
	conOut(x + 2, y) << (char)colt_dreapta_sus;
	for (auto i = y+1; i <= y + 14; ++i)
	{
		conOut(x, i) << (char)linie_verticala;
		conOut(x+2, i) << (char)linie_verticala;
		
	}
	conOut(x, y + 14) << (char)colt_stanga_jos;
	conOut(x + 1, y+14) << (char)linie_orizontala;
	conOut(x + 2, y + 14) << (char)colt_dreapta_jos;
	conOut(x + 1, y + 3) << "H";
	conOut(x + 1, y + 6) << "O";
	conOut(x + 1, y + 9) << "M";
	conOut(x + 1, y + 12) << "E";
}
void doScoreBoard(int x, int y)
{
	x = x - 10;
	y = y -4;
	conOut(x, y) << (char)colt_stanga_sus;
	conOut(x, y + 4) << (char)colt_stanga_jos;
	conOut(x + 1, y) << (char)linie_orizontala;
	conOut(x + 2, y) << (char)linie_orizontala;
	conOut(x + 3, y) << (char)linie_orizontala;
	conOut(x + 4, y) << (char)linie_orizontala;
	conOut(x + 5, y) << (char)linie_orizontala;
	conOut(x + 6, y) << (char)linie_orizontala;
	conOut(x + 7, y) << (char)linie_orizontala;
	conOut(x + 8, y) << (char)linie_orizontala;
	conOut(x + 9, y) << (char)linie_orizontala;
	conOut(x + 10, y) << (char)colt_dreapta_sus;
	conOut(x, y + 1) << (char)linie_verticala;
	conOut(x , y + 2) << (char)linie_verticala;
	conOut(x , y + 3) << (char)linie_verticala;
	conOut(x+10 , y + 3) << (char)linie_verticala;
	conOut(x + 10, y + 1) << (char)linie_verticala;
	conOut(x + 10, y + 2) << (char)linie_verticala;
	conOut(x + 10, y + 4) << (char)colt_dreapta_jos;
	conOut(x + 4, y + 4) << (char)linie_orizontala;
	conOut(x + 3, y + 4) << (char)linie_orizontala;
	conOut(x + 2, y + 4) << (char)linie_orizontala;
	conOut(x + 1, y + 4) << (char)linie_orizontala;
	conOut(x + 5, y + 4) << (char)linie_orizontala;
	conOut(x + 6, y + 4) << (char)linie_orizontala;
	conOut(x + 7, y + 4) << (char)linie_orizontala;
	conOut(x + 8, y + 4) << (char)linie_orizontala;
	conOut(x + 9, y + 4) << (char)linie_orizontala;
	conOut(x + 1, y + 1) << "Score:";
	conOut(x + 1, y + 3) << "Money:";

}
void Map::drawSF()
{
	conOut(52, 12) << "S";
	conOut(51, 13) << "80$";
}
void Map::drawPS()
{
	conOut(52, 17) << "P";
	conOut(51, 18) << "50$";
}
Map::Map(int x,int y,int lvl)
{
	for (int i = 1; i <50;  i=i+6)
	   for (int j = 1; j <lvl*5-1; j=j+3)
	      doPatrat(i+60,j+10);

	for (int i = 1; i <50; i = i + 8)
		doPatrat1(i + 60, 8);

	for (int i = 1; i <15; i = i + 5)
		doPatrat2(50, i+10);

	doHome(60,11);
	doScoreBoard(60, 10);
	drawSF();
	drawPS();
}
 Map *Map::getInstance(int lvl)
{
	if (Map::instance==nullptr)
	{
	Map::instance = new Map(1,1,lvl);

	}
	return Map::instance;

}

Map::~Map()
{
	delete instance;
}

