#pragma once
#include "Obiect.h"
class Proiectil;

class Planta :
	public Obiect
{
protected:
	int hp;

public:
	Planta(Casuta* c);
	~Planta();

	virtual Proiectil* impusca() = 0;
	void scadehp(int);
	int gethp();
};
