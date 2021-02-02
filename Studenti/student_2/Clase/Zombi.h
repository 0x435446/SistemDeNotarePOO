#pragma once
#include "Zombie.h"
class Zombi :public Zombie
{
	int viata = 100;
public:
	Zombi() :Zombie() {}
	Zombi(int x, int y);
	void print(int x, int y)override;
	~Zombi();
};

