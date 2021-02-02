#pragma once

#include "Casuta.h"

class Obiect
{
protected:
	char c;
	Casuta* casuta;

public:
	Obiect(Casuta*);
	~Obiect();

	Casuta* getCasuta();
	void afiseaza();
};

