#include "Zombie.h"



Zombie::Zombie()
{
	srand(time(NULL));
	int random_poz = 0;
	do
		random_poz = rand() % 21;
	while (random_poz % 5 != 0);
	this->x_coord = 12 + random_poz;
	this->y_coord = 91;
}


Zombie::~Zombie()
{
}

const void Zombie::print_entity() const
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	BattleField *bf; bf = bf->GetInstance();
	
	conOut(this->x_coord,this->y_coord) << "Z";
	bf->set_field_position(this->x_coord,this->y_coord, 'z');
}



const int Zombie::get_health() const
{
	return this->health;
}

const int Zombie::attack() const
{
	return this->damage;
}

const void Zombie::move()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	BattleField *bf; bf = bf->GetInstance();
	conOut(this->x_coord, this->y_coord) << " ";
	bf->set_field_position(this->x_coord, this->y_coord, '0');
	this->y_coord -= 7;
	conOut(this->x_coord, this->y_coord) << "Z";
	bf->set_field_position(this->x_coord, this->y_coord, 'z');
}

