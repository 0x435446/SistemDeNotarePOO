#pragma once
#include "Entity.h"
#include "Zona.h"
#include <vector>

class Plant:public Entity
{
protected:
	int x, y;
	std::vector<Zona*>vect;
public:
	Plant();
	Plant(int, int);
	~Plant();
	void update(std::string action);
	void draw();
	void set_position(int a, int b);
};

