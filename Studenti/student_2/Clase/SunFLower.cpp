#include "SunFLower.h"



SunFlower::SunFlower(int x,int y) : Plant(x,y)
{

}

void SunFlower::print(int x,int y)
{
	this->set = true;
	conOut(x, y) << "Sun";
	conOut(x+1, y-1) << "Flower";
}

SunFlower::~SunFlower()
{
}
