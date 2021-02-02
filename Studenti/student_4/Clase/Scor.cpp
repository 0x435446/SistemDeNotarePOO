#include "Scor.h"

int Scor::Get_Scor()
{
	return Scor::Scoruleanu;
}

void Scor::Afis_Scor()
{	
	string Scorr = to_string(Scor::Get_Scor());
	Consola::gotoYXMov(2, 1, Scorr);
}

void Scor::Increase_Scor(int Q)
{
	Scor::Scoruleanu = Scor::Scoruleanu + Q;
}

Scor* Scor::Set_Instanta()
{
	if (Scor::Instanta == NULL)
		Scor::Instanta = new Scor();
	return Scor::Instanta;
}

Scor* Scor::Instanta = NULL;
int Scor::Scoruleanu = 0;