#pragma once
#include "Entity.h"
class Sun :
	public Entity
{
public:
	Sun(int x, int y);
	~Sun();
	virtual void interactWith(Zombie &e);
	virtual void interactWith(PeaShooter &e);
	virtual void interactWith(Pea &e);
	virtual void interact(Entity &e);
};

