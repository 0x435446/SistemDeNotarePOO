#pragma once
#include "Plant.h"
#include "Pea.h"
#include<vector>

class Peashooter :
	public Plant
{
private:
	int x, y;
	std::vector<Pea*> pea_vect;
	int valoare, frecventa, rezistenta;
public:
	Peashooter();
	Peashooter(int, int);
	~Peashooter();
	void update(std::string) {}
	void draw();
	void action();
	void set(int valoare, int frecventa, int rezistenta);
};

