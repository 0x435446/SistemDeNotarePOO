#pragma once
#include "Obiect.h"
class Zombie :
	public Obiect
{
protected:
	int hp;
	int damage;

public:
	Zombie(Casuta* c);
	~Zombie();

	void scadehp(int);
	int loveste(int);
	int gethp();
	bool ajunsLaCasa(int d);
};

