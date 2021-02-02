#include "Peashooter.h"
#include "Pea.h"

int Peashooter::cost = 100;

Peashooter::Peashooter(Casuta* c) :Planta(c)
{
	this->c = 'P';
	this->hp = 5;
	this->rataimpuscare = 50;
}


Peashooter::~Peashooter()
{
}

Proiectil* Peashooter::impusca()
{
	static int nrbucle = 0;
	if (nrbucle == rataimpuscare)
	{
		nrbucle = 0;
		Casuta* urm = new Casuta(this->casuta->r, this->casuta->c + 5);
		return new Pea(urm);
	}
	else
		nrbucle++;
	return nullptr;
}
