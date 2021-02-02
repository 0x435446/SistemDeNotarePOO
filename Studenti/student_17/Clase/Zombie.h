#pragma once
#include "DisplayableEntity.h"
#include "Plant.h"

#define ZOMBIE_HP		100
#define ZOMBIE_SPEED	30

enum ZombieType
{
	NoZombieType = 0, NormalZombieType, BucketHeadZombieType, PoleVaultingZombieType, SuperZombieType
};

class Zombie : public DisplayableEntity
{
public:
	Zombie();
	virtual ~Zombie();
	ZombieType GetType() const;
	int GetHp() const;

	void GetHit(int damage, int descrease_speed);
	void BitePlant(Plant& plant);
protected:
	void SetType(const ZombieType type);
	void SetHp(const int hp);
private:
	static unsigned int s_zombieIdCounter;
	unsigned int m_zombieId;
	ZombieType m_type;
	int m_hp;
};