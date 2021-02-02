#pragma once
#include "Entity.h"
#include "ConsoleOutput.h"
class Zombies : public Entity
{
public:
	Zombies();
	virtual ~Zombies();
	virtual const void print_entity()const = 0;
	virtual const int get_health() const = 0;
	virtual const int attack() const = 0;
	virtual const void move() = 0;
	virtual const int get_x() = 0;
	virtual const int get_y() = 0;
};

