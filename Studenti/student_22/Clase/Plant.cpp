#include "Plant.h"
#define base_health 2
#define base_comeBackAttack 0
Plant::Plant(int pozX, int pozY) : Entity(pozX, pozY, false, 0)
{
	health = base_health;
	comeBackAttak = base_comeBackAttack;
}

Plant::~Plant()
{
}

float Plant::getHealth()
{
	return this->health;
}

void Plant::setHealth(float health)
{
	this->health = health;
}

std::string Plant::getAttackingType()
{
	return "normal";
}

float Plant::getComeBackAttack()
{
	return this->comeBackAttak;
}

//void Plant::special(PooVsZom * e)
//{
//}



