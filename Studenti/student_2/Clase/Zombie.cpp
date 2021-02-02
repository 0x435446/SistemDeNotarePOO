#include "Zombie.h"
#include<windows.h>


Zombie::Zombie()
{
}

Zombie::Zombie(int x,int y)
{
	this->x = x;
	this->y = y;

}
void Zombie::print(int x,int y)
{
}

void Zombie::erase()
{
	conOut(x, y) << "       ";
}

void Zombie::move()
{	
		y = y - 1;
		Sleep(500);
		erase();
		print(x, y);	
}


Zombie::~Zombie()
{
}
