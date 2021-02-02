#include "Pea.h"



Pea::Pea(int x, int y) : Entity(x, y, "o")
{
	movement = 1;
}


Pea::~Pea()
{
}

void Pea::interactWith(Zombie & e)
{
}

void Pea::interactWith(PeaShooter & e)
{
}

void Pea::interactWith(Pea & e)
{
}

void Pea::interact(Entity & e)
{
	e.interactWith(*this);
}
