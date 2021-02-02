#include "SunFlower.h"



SunFlower::SunFlower(int cost,int rezistenta):
	Plante(cost,rezistenta)
{
}

void SunFlower::colectare_plante(Teren t, int x, int y)
{
	Log::get_instance().logevent("S-a dat dublu click pe sunflower\n");
	t.gotoXY(x, y);
	printf("S");
}

void SunFlower::plaseaza_plante(Teren t, int x, int y)
{
	Log::get_instance().logevent("Se plaseaza sunflower\n");
	t.gotoXY(x, y);
	printf("S");
}

SunFlower::~SunFlower()
{
}
