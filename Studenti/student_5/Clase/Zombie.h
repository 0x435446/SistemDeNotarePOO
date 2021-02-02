#pragma once
#include "Entity.h"
#include <chrono>

class Zombie :
	public Entity
{
public:
	Zombie(int x, int y, int hp);
	~Zombie();
	virtual void interactWith(Zombie &e);
	virtual void interactWith(PeaShooter &e);
	virtual void interactWith(Pea &e);
	virtual void interact(Entity &e);
private:
	int hp;
	
};

