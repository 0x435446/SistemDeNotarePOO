#include "Wallnut.h"

int Wallnut::cost = 50;


Wallnut::Wallnut(Casuta* c) :Planta(c)
{
	this->hp = 15;
	this->c = 'D';
}


Wallnut::~Wallnut()
{
}

Proiectil* Wallnut::impusca()
{
	return nullptr;
}