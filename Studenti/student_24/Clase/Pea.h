#pragma once
#include "Entity.h"
class Pea
{
	int x, y;
	int life;
	int damage;
public:
	int getx();
	int gety();
	void setlife(int x);
	int getlife();
	Pea(int a, int b);
	void uppdate(std::string action);
	void draw();
	Pea();
	~Pea();
};

