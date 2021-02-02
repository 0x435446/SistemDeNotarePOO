#include "Zombie.h"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

Zombie::Zombie(int speed, int health, char symbol)
{
	Speed = speed;
	Health = health;
	Symbol = symbol;
}

int Zombie::GetHealth()
{
	return Health;
}

void Zombie::ReduceHealth(int reduce)
{
	Health = Health - reduce;
}
