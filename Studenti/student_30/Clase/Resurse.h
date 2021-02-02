#pragma once
#include "Entity.h"
#include<vector>
#include "Zona.h"

class Resurse :
	public Entity
{
protected:
	int x, y;
	std::vector<Zona*>vect;
public:
	Resurse();
	Resurse(int,int);
	~Resurse();
	void set_position(int a, int b);
	void update(std::string);
	void draw();
};

