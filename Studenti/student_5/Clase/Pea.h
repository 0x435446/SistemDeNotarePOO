#pragma once
#include "Entity.h"
class Pea :
	public Entity
{
public:
	Pea(int x, int y);
	~Pea();
	virtual void interactWith(Zombie &e) ;
	virtual void interactWith(PeaShooter &e);
	virtual void interactWith(Pea &e);
	virtual void interact(Entity &e);
};

