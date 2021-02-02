#include "Planta.h"



Planta::Planta(Casuta* c) : Obiect(c)
{
}


Planta::~Planta()
{
}

void Planta::scadehp(int x)
{
	hp -= x;
}

int Planta::gethp()
{
	return hp;
}