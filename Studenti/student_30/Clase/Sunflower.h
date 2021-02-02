#pragma once
#include "Plant.h"
#include "Pea.h"

class Sunflower :
	public Plant
{
private:
	int x, y;
	std::vector<Pea*> pea_vect;
	int valoare, frecventa, rezistenta;
public:
	Sunflower();
	Sunflower(int, int);
	~Sunflower();
	void update(std::string) {}
	void draw();
	void action();
	void set(int valoare, int frecventa, int rezistenta);
};

