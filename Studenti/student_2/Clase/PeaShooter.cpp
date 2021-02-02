#include "PeaShooter.h"


PeaShooter::PeaShooter(int x, int y) : Plant(x, y)
{
}

void PeaShooter::print(int x, int y)
{
	this->set = true;
	conOut(x, y) << "Pea";
	conOut(x + 1, y - 1) << "Shooter";
}

PeaShooter::~PeaShooter()
{
}
