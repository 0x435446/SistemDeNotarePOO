#pragma once
#include "Plant.h"
class Frozen_Peashooter : public Plant 
{
private:
	int health = 100;
	int x_coord;
	int y_coord;
public:
	Frozen_Peashooter(int x, int y);
	Frozen_Peashooter();
	~Frozen_Peashooter();
	const int get_health() const { return health; };
	const void print_entity()const;
	const void shoot_projectiles()const;
};

