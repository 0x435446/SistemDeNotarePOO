#pragma once
#include "Entity.h"
class Plant : public Entity
{
public:
	Plant();
	virtual ~Plant();
	virtual const int get_health()const = 0;
	virtual const void print_entity()const = 0;
	virtual const void shoot_projectiles()const = 0;
};

