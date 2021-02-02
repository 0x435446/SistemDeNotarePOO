#include "Wall_nut.h"



Wall_nut::Wall_nut(int x, int y) : Plant(x, y)
{
}
void Wall_nut::print(int a, int b)
{
	this->set = true;
	conOut(a, b) << "Wall";
	conOut(a + 1, b) << "Nut";
}

Wall_nut::~Wall_nut()
{
}
