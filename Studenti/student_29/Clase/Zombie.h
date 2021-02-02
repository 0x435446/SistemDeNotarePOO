#pragma once
#include "Entity.h"
class Zombie : public Entity
{
protected:
	int move_speed;
public:
	Zombie(const unsigned int&, const unsigned int&, char);
	void move();
	~Zombie();
};

