#include "CherryBomb.h"



CherryBomb::CherryBomb(int x, int y) : Plant(x, y)
{
}
void CherryBomb::print(int a, int b)
{
	this->set = true;
	conOut(a, b) << "Cherry";
	conOut(a + 1, b) << "Bomb";
}

CherryBomb::~CherryBomb()
{
}
