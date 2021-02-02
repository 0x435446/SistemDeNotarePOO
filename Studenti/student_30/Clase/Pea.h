#pragma once
#include "Proiectile.h"
class Pea :
	public Proiectile
{
private:
	int x, y;
	int efect;
public:
	Pea();
	Pea(int, int);
	~Pea();
	void move();
};

