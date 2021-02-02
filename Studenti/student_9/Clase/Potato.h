#pragma once
#include "Plant.h"
class Potato : public Plant
{
private:
	int health = 300;
	int x_coord;
	int y_coord;

public:
	Potato(int x, int y);
	Potato();
	~Potato();
	const int get_health() const { return health; };
	const void print_entity()const;
	const void shoot_projectiles()const {};
};

