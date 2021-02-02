#include "Zombie.h"



Zombie::Zombie()
{
}

Zombie::Zombie(const int health, const int speed, const int damage, const std::string name, const int x, const int y)
{
	this->health = health;
	this->speed = speed;
	this->damage = damage;
	this->name = name;
	this->x = x;
	this->y = y;
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->y, this->x) << this->name;
}

Zombie::Zombie(const int health, const int speed, const int damage, const std::string name, const int x, const int y, const int special_ability)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	this->health = health;
	this->speed = speed;
	this->damage = damage;
	this->name = name;
	this->x = x;
	this->y = y;
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->y, this->x) << this->name;
	this->special_ability = special_ability;
}


void Zombie::move()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->y, this->x) << " ";
	this->x -= 1;
	if (x % 5 == 0)
		this->x -= 1;
	conOut(this->y, this->x) << this->name;
}

void Zombie::takeDamage(const int damageValue)
{
	this->health -= damageValue;
}

void Zombie::modifyX(int value)
{
	this->x = this->x - value;
}

const int Zombie::getAbilityCharges()
{
	return this->special_ability;
}

void Zombie::decreaseCharges()
{
	this->special_ability = 0;
}

void Zombie::slowMovement(const int value)
{
	this->speed = this->speed - value;
}

Zombie::~Zombie()
{
}
