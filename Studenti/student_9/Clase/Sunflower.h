#pragma once
#include "Plant.h"
class Sunflower : public Plant
{
private:
	int health = 80;
	int x_coord;
	int y_coord;
public:
	Sunflower(int x, int y);
	Sunflower();
	~Sunflower();
	const int get_health() const { return health; };
	const void print_entity()const;
	const void shoot_projectiles()const{};
};

