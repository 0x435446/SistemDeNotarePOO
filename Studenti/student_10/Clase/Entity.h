#pragma once
#include <iostream>
#include <vector>
#include <string>


#include "Lane.h"
enum type { PLANT, PLANT_WALLNUT, PLANT_SUNFLOWER, PLANT_PEASHOOTER, PLANT_CHERRY_BOMB, PLANT_SNOW_PEA, ZOMBIE, ZOMBIE_POLE_VAULTING, ZOMBIE_BUCKET_HEAD, ZOMBIE_SUPER_ZOMBIE, PROJECTILE, NONE };


using namespace std;


class Lane;



class Entity
{
private:
	
protected:
	type type_;
	int hp;
	Lane* lane;

public:
	Entity(type type_, Lane* lane);
	~Entity();

	int get_type_id() {
		if (this->get_type() == ZOMBIE) {
			return 0;
		}
		if (this->get_type() == ZOMBIE_BUCKET_HEAD) {
			return 1;
		}
		if (this->get_type() == ZOMBIE_POLE_VAULTING) {
			return 2;
		}
		if (this->get_type() == ZOMBIE_SUPER_ZOMBIE) {
			return 3;
		}

		return -1000;
	}

	type& get_type() {
		return this->type_;
	}

	virtual void tick() = 0;
	virtual string draw() = 0;


	int get_position(Lane* lane);

	virtual int get_hp() {
		return this->hp;
	}
	void set_hp(int hp) {
		this->hp = hp;
	}

	virtual int get_id() {
		return -9999;
	}
};
