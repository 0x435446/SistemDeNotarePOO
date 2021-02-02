#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Entity.h"
#include "Lane.h"
#include "Projectile.h"
#include "History.h"
#include "Level.h"

using namespace std;

class Entity;

#define CHERRY_BOMB_DAMAGE 1000

class Plant : public Entity
{
private:
	
	int damage;

public:
	Plant(type type_, Lane* lane) ;
	~Plant();

	void tick();
	string draw();

	static int get_cost(type type_) {
		if (type_ == PLANT_CHERRY_BOMB) {
			return 50;
		}
		if (type_ == PLANT_PEASHOOTER) {
			return 30;
		}
		if (type_ == PLANT_WALLNUT) {
			return 100;
		}
		if (type_ == PLANT_SNOW_PEA) {
			return 40;
		}
		if (type_ == PLANT_SUNFLOWER) {
			return 20;
		}
		return -10;
	}

	
	int get_plant_cost() {
		return Plant::get_cost(this->type_);
	}
};

