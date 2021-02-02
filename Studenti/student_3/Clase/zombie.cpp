#include "zombie.h"


zombie::zombie(int x, int y)
{
	this->nume = "zombie";
	pos_x = x;
	pos_y = y;
	lifePoints = 100;
	this->speed = 5;
	dead = false;
	attackPoints = 20;
	Log::getInstance().displayMessage("Creare zombie.\n");
}

void zombie::drawZombie(int x, int y)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << "zomb";
	Log::getInstance().displayMessage("Printare zombie.\n");
}

void zombie::stergereZombie(int x, int y)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << "    ";
}

zombie zombie::operator-(int k)
{
	this->pos_x = this->pos_x - k;
	return *this;
}

zombie & zombie::operator=(const zombie &C)
{
	if (this != &C)
	{
		this->pos_x = C.pos_x;
		this->pos_y = C.pos_y;
		this->lifePoints = C.lifePoints;
		this->activ = C.activ;
		this->attackPoints = C.attackPoints;
		this->speed = C.speed;
	}
	return *this;
}

zombie::~zombie()
{
	Log::getInstance().displayMessage("Stergere zombie.\n");
}

int zombie::fightWith(std::string nume, int life)
{
	if (this->getNume() != nume)
	{
		life -= this->attackPoints;
		this->speed = 0;
		return life;
	}
	if (life == 0)
	{
		this->speed = 5;
	}
	return life;
		
}
