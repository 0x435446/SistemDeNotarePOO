#pragma once
#include "Planta.h"

class Wallnut :
	public Planta
{
public:
	Wallnut(Casuta*);
	~Wallnut();

	static int cost;

	Proiectil* impusca() override;
};


