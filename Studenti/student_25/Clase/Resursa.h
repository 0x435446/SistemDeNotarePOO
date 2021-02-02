#pragma once
#include "Obiect.h"
class Resursa :
	public Obiect
{
protected:
	int puncte;
public:
	Resursa(Casuta* c);
	~Resursa();

	int getPuncte();
};

