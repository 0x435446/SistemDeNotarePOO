#include "Sunflower.h"
#include "ConsoleOutput.h"
#include "Resources.h"

void Sunflower::set(int price, int resistance, int grow_time)
{
	this->price = price;
	this->resistance = resistance;
	this->grow_time = grow_time;
}

void Sunflower::ability()
{
	Resources *resource = Resources::getinstance();
	resource->lowfrecv(1);


}

void Sunflower::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << "(O)";
	conOut(x + 1, y) << " | ";
	conOut(x + 2, y) << "---";



}

void Sunflower::shot()
{
}

void Sunflower::uppdate(std::string)
{
	draw();
}

Sunflower::Sunflower(int a, int b)
{
	x = a+1;
	y = b+3;
	
}

Sunflower::Sunflower()
{

}


Sunflower::~Sunflower()
{
}
