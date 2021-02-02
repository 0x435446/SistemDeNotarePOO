#pragma once
#include "Zombie.h"
class Zombie_banal :
	public Zombie
{
private:
	int rezistenta;
	int x, y;
	int viteza;
public:
	Zombie_banal();
	Zombie_banal(int, int);
	~Zombie_banal();
	void update(std::string) {}
	void draw();
	void move();
	void set(int viteza, int rezistenta);
};

