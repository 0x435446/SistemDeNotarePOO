#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Caractere
{

private:
	static Caractere* INStanta;
	Caractere(char ColtDrSus, char ColtDrJos, char ColtStSus, char ColtStJos, char X, char TDr, char TSt, char Linie, char Coloana, char Perp);

public:
	static Caractere* SetINStanta(char ColtDrSus, char ColtDrJos, char ColtStSus, char ColtStJos, char X, char TDr, char TSt, char Linie, char Coloana, char Perp);

	static string ColtDrSus;
	static string ColtDrJos;
	static string ColtStSus;
	static string ColtStJos;
	static string X;
	static string TDr;
	static string TSt;
	static string Linie;
	static string Coloana;
	static string Perp;
};

