#include "ConsoleOutput.h"
#include "Obiect.h"


Obiect::Obiect(Casuta* casuta) :casuta(casuta)
{
}


Obiect::~Obiect()
{
}

Casuta* Obiect::getCasuta()
{
	return casuta;
}

void Obiect::afiseaza()
{
	UserInterface::ConsoleOutput::getInstance()(casuta->r, casuta->c) << this->c;
}