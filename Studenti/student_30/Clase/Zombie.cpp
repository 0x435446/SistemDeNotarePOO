#include "Zombie.h"
#include "Zombie_banal.h"


Zombie::Zombie()
{
}

Zombie::Zombie(int a, int b)
{
	x = a;
	y = b;
}

Zombie::~Zombie()
{
}

void Zombie::update(std::string action)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	Zombie_banal zombie1(vect[0]->get_x() + 2, vect[0]->get_y() + 2);
	vect[0]->set_filed();
	zombie1.draw();
}