#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Entity.h"
#include "Lane.h"

using namespace std;

class Entity;

class Projectile : public Entity
{
private:
	bool has_ticked = false;
	static int projectile_counter;
	int id;
	bool has_impacted = false;
	int damage;
public:
	Projectile(Lane* lane, int damage);
	~Projectile();

	virtual void tick();
	virtual string draw();

	void set_ticked(bool tick) {
		this->has_ticked = tick;
	}

	int get_id();

	void set_impacted(bool impacted) {
		this->has_impacted = impacted;
	}

	bool get_impacted() {
		return this->has_impacted;
	}
};

