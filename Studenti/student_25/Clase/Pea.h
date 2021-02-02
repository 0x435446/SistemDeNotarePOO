#pragma once
#include "Proiectil.h"
class Pea :
	public Proiectil
{
public:
	Pea(Casuta*);
	~Pea();

	int loveste(int dist);
};


