#pragma once
#include "Zombies.h"
class Zombie : public Zombies
{
private:
	int health = 100;
	int x_coord = 91;
	int y_coord;
	int damage = 30;
public:
	Zombie();
	~Zombie();
	const void print_entity()const;
	const int get_health() const;
	const int attack() const;
	const void move();
	const int get_x() { return x_coord; };
	const int get_y() { return y_coord; };
};

