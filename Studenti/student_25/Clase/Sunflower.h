#pragma once
#include "Planta.h"
class Sunflower :
	public Planta
{
public:
	Sunflower(Casuta*);
	~Sunflower();

	static int cost;

	Proiectil* impusca() override;
};

