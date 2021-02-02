#pragma once
#include "Entity.h"
#include "Time.h"
class Zombie : public Entity
{
private:
	int life;
	int x, y;
	Time t;
public:
	int getx();
	int gety();
	int getlife();
	void lifeminus(int x);
	Zombie(int a, int b);
	void draw();
	void uppdate(std::string);
	~Zombie();
};

