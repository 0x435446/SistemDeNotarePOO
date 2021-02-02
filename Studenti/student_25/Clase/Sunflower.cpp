#include "Sunflower.h"
int Sunflower::cost = 50;

Sunflower::Sunflower(Casuta* c) :Planta(c)
{
	this->c = 'Y';
	this->hp = 3;
}

Sunflower::~Sunflower()
{
}

Proiectil* Sunflower::impusca()
{
	return nullptr;
}
