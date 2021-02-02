#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Entity.h"
#include "Lane.h"
#include "History.h"

using namespace std;
class Entity;
class Lane;

class Zombie : public Entity
{
private:
	int speed;
	int frozent_duration;
	bool has_vaulted = false;
protected:
	
public:

	Zombie(type type_, Lane* lane); 
	~Zombie();

	
	bool shouldMove(Lane* lane);
	void move(Lane* lane);
	void tick();
	string draw();
};

