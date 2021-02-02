#include "SnowPea.h"



SnowPea::SnowPea(int x, int y) : Plant(x, y)
{
}

void SnowPea::print(int a, int b)
{
	this->set = true;
	conOut(a, b) << "Snow";
	conOut(a + 1, b) << "Pea";
}

SnowPea::~SnowPea()
{
}
