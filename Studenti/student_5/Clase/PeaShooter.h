#pragma once
#include "Entity.h"
#include <chrono>
class PeaShooter : public Entity
{
public:
	PeaShooter(int x, int y, std::string &&glyph);
	~PeaShooter();
	virtual void interactWith(Zombie &e);
	virtual void interactWith(PeaShooter &e);
	virtual void interactWith(Pea &e);
	virtual void interact(Entity &e);
	bool getSpecial() override;
private:
	
	
};

