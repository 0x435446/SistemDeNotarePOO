#include "Peashooter.h"
#include"Pea.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Coordonate.h"
#include"Teren.h"
#include <time.h>
#include <chrono>


Peashooter::Peashooter(int cost,int rezistenta):
	Plante(cost,rezistenta)
{
}

void Peashooter::colectare_plante( Teren t, int x,int y)
{
	Log::get_instance().logevent("S-a dat dublu click pe peashooter\n");
	t.gotoXY(x, y);
	printf("P");
}

void Peashooter::plaseaza_plante( Teren t,int x,int y)
{
	Log::get_instance().logevent("Se plaseaza peashooter\n");
	t.gotoXY(x, y);
	printf("P");
}

Peashooter::~Peashooter()
{
}
