#include "Caractere.h"

Caractere::Caractere(char ColtDrSus, char ColtDrJos, char ColtStSus, char ColtStJos, char X, char TDr, char TSt, char Linie, char Coloana, char Perp)
{
	Caractere::ColtDrSus = ColtDrSus;
	Caractere::ColtDrJos = ColtDrJos;
	Caractere::ColtStSus = ColtStSus;
	Caractere::ColtStJos = ColtStJos;
	Caractere::X = X;
	Caractere::TDr = TDr;
	Caractere::TSt = TSt;
	Caractere::Linie = Linie;
	Caractere::Coloana = Coloana;
	Caractere::Perp = Perp;
}

Caractere* Caractere::SetINStanta(char ColtDrSus, char ColtDrJos, char ColtStSus, char ColtStJos, char X, char TDr, char TSt, char Linie, char Coloana, char Perp)
{
	if (Caractere::INStanta == NULL)
		INStanta = new Caractere(ColtDrSus, ColtDrJos, ColtStSus, ColtStJos, X, TDr, TSt, Linie, Coloana, Perp);
	return Caractere::INStanta;
}

