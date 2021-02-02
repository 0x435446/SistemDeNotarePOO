#pragma once
#include "Planta.h"
class Peashooter :
	public Planta
{
public:
	Peashooter(Casuta*);
	~Peashooter();

	static int cost;
	int rataimpuscare;

	Proiectil* impusca() override;
};

