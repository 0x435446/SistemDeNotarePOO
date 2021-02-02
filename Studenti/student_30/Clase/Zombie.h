#pragma once
#include "Entity.h"
#include<vector>
#include "Zona.h"
class Zombie :
	public Entity
{
protected:
		int x, y;
		std::vector<Zona*>vect;
public:
	Zombie();
	Zombie(int, int);
	~Zombie();
	void update(std::string action);
	void draw() {}
	void set_position(int a, int b);
};

