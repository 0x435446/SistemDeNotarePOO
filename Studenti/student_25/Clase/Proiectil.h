#pragma once
#include "Obiect.h"
class Proiectil :
	public Obiect
{
protected:
	int damage;

public:
	Proiectil(Casuta*);
	~Proiectil();

	virtual int loveste(int) = 0;
};

