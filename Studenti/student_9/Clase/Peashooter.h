#pragma once
#include "Plant.h"
class Peashooter : public Plant
{
private:
	int health = 100;
	int x_coord;
	int y_coord;

public:
	Peashooter(int x, int y);
	~Peashooter();
	const int get_health() const { return health; };
	const void print_entity()const;
	const void shoot_projectiles()const;
};

