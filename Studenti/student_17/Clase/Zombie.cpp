#include "Zombie.h"

unsigned int Zombie::s_zombieIdCounter = 0;

Zombie::Zombie() : m_zombieId(Zombie::s_zombieIdCounter), m_type(NoZombieType), m_hp(ZOMBIE_HP)
{
	this->SetMoving(true);
	this->SetDirection(LEFT);
	this->SetSpeed(ZOMBIE_SPEED);
	Zombie::s_zombieIdCounter++;
}

Zombie::~Zombie()
{
}

ZombieType Zombie::GetType() const
{
	return this->m_type;
}

int Zombie::GetHp() const
{
	return this->m_hp;
}

void Zombie::GetHit(int damage, int descrease_speed)
{
	this->m_hp -= damage;
	if (this->m_hp < 0)
		delete this;
	this->SetSpeed((this->GetSpeed()) * (100 - descrease_speed) / 100);
}

void Zombie::BitePlant(Plant& plant)
{
	plant.GetBitten();
}

void Zombie::SetType(const ZombieType type)
{
	this->m_type = type;
}

void Zombie::SetHp(const int hp)
{
	this->m_hp = hp;
}