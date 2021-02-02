#pragma once
#include "Plant.h"
class Cherrybomb : public Plant
{
private:
	int health = 0;
	int x_coord;
	int y_coord;
public:
	Cherrybomb();
	Cherrybomb(int x, int y);
	~Cherrybomb();
	const int get_health() const { return health; };
	const void print_entity()const;
	const void shoot_projectiles()const {};
};

