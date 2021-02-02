#include "Zombie.h"
#define base_health 2
#define base_movingSpeed 1.25f;


Zombie::Zombie(int pozX, int pozY, bool isMoving): Entity(pozX, pozY, isMoving, -1)
{
	health = base_health;
	movingSpeed = base_movingSpeed;
	canJump = false;
}


Zombie::~Zombie()
{
}

void Zombie::interact(Missile **e)
{
	this->movingSpeed *= (*e)->getSpecial();
	if (this->health - 1 <= 0) {
		this->isMoving = false;
		this->isDead = true;
	}
	else
		this->health--;
	(*e)->setIsMoving(false);
	(*e)->setIsDead(true);
}

void Zombie::interact(Plant **e) {
	float plantHealth = (*e)->getHealth() -1;
	if (plantHealth == 0) {
		this->isMoving = true;
		(*e)->setIsDead(true);
	}
	(*e)->setHealth(plantHealth);
	this->health -= (*e)->getComeBackAttack();
	if (this->health <= 0) {
		this->isMoving = false;
		this->isDead = true;
	}

}

void Zombie::jump(Plant * e, int spriteSize)
{
}

void Zombie::setHealth(float health)
{
	this->health = health;
}

float Zombie::getHealth()
{
	return this->health;
}

bool Zombie::getCanJump()
{
	return canJump;
}

