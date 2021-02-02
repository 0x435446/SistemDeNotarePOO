#pragma once
#include "Entity.h"
#include "Missile.h"
#include "Plant.h"
#include "CherryBomb.h"
class Zombie :
	public Entity
{
public:
	Zombie(int pozX, int pozY, bool isMoving);
	~Zombie();
	virtual void interact(Missile** e);
	virtual void interact(Plant** e);
	virtual void jump(Plant* e, int spriteSize);
	//virtual void interact(CherryBomb** e);
	void setHealth(float health);
	float getHealth();
	bool getCanJump();
protected:
	float health;
	bool canJump;
};

