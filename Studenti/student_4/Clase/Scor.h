#pragma once
#include "Consola.h"
class Scor
{
private:
	Scor() {};
	static Scor* Instanta;
	static int Scoruleanu;
public:
	static int Get_Scor();
	static void Afis_Scor();
	static void Increase_Scor(int Q);
	static Scor* Set_Instanta();
};

