#include "Pea.h"

Pea::Pea(Casuta* c) :Proiectil(c)
{
	this->c = '*';
	this->damage = 10;
}


Pea::~Pea()
{
}

int Pea::loveste(int dist)
{
	static int nrbucle = 0;
	if (nrbucle == dist)
	{
		return damage;
	}
	else
	{
		nrbucle++;
		return 0;
	}
}

