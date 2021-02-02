#include "Map.h"

Map* Map::SetInstanta()
{
	if (instanta == NULL) {
		instanta = new Map();
	}
	return instanta;
}

void Map::Afis()
{
	while (0 != 1) {
		Map::Linia_1();

	}
}

void Map::Linia_1()
{
	//int i = 0;
	//for (int j = 0; j < 91; j++)
	//{
	//	if (j % 10 != 0 && j<90)
	//		Consola::gotoYX(j, i, Caractere::Linie);
	//	if(j % 10 == 0 && j < 90)
	//		Consola::gotoYX(j, i, Caractere::Perp);
	//	if (j == 90)
	//		Consola::gotoYX(j, i, Caractere::ColtDrSus);
	//	if (j == 0)
	//		Consola::gotoYX(j, i, Caractere::ColtStSus);
	//	
	//}

	//for in for si gata treaba

}

void Map::Mapa()
{
	for (int i = 0; i <= 100; i++)
	{
		Consola::gotoYXVerde(i, 0, Caractere::Linie);
	}
	for (int i = 0; i <= 100; i++)
	{
		Consola::gotoYXVerde(i, 5, Caractere::Linie);
	}
	for (int i = 0; i <= 100; i++)
	{
		Consola::gotoYXVerde(i, 10, Caractere::Linie);
	}
	for (int i = 0; i <= 100; i++)
	{
		Consola::gotoYXVerde(i, 15, Caractere::Linie);
	}
	for (int i = 0; i <= 100; i++)
	{
		Consola::gotoYXVerde(i, 20, Caractere::Linie);
	}
	for (int i = 0; i <= 100; i++)
	{
		Consola::gotoYXVerde(i, 25, Caractere::Linie);
	}
	for (int i = 0; i <= 100; i++)
	{
		Consola::gotoYXVerde(i, 30, Caractere::Linie);
	}
	//Coloanele
	for (int i = 0; i < 31; i++) {
		Consola::gotoYXVerde(0, i, Caractere::Coloana);
	}
	for (int i = 0; i < 31; i++) {
		Consola::gotoYXVerde(10, i, Caractere::Coloana);
	}
	for (int i = 0; i < 31; i++) {
		Consola::gotoYXVerde(20, i, Caractere::Coloana);
	}
	for (int i = 0; i < 31; i++) {
		Consola::gotoYXVerde(30, i, Caractere::Coloana);
	}
	for (int i = 0; i < 31; i++) {
		Consola::gotoYXVerde(40, i, Caractere::Coloana);
	}
	for (int i = 0; i < 31; i++) {
		Consola::gotoYXVerde(50, i, Caractere::Coloana);
	}
	for (int i = 0; i < 31; i++) {
		Consola::gotoYXVerde(60, i, Caractere::Coloana);
	}
	for (int i = 0; i < 31; i++) {
		Consola::gotoYXVerde(70, i, Caractere::Coloana);
	}
	for (int i = 0; i < 31; i++) {
		Consola::gotoYXVerde(80, i, Caractere::Coloana);
	}
	for (int i = 0; i < 31; i++) {
		Consola::gotoYXVerde(90, i, Caractere::Coloana);
	}
	for (int i = 0; i < 31; i++) {
		Consola::gotoYXVerde(100, i, Caractere::Coloana);
	}
}


Consola* Consola::INstanta = NULL;

char CStS = 201;
string CSS(1, CStS);

char ColDJ = 188;
string CDJ(1, ColDJ);

char ColDS = 187;
string CDS(1, ColDS);

char Col = 186;
string C(1, Col);

char Linie = 205;
string L(1, Linie);

char Perp = 203;
string PERP(1, Perp);

char ColSJ = 200;
string CSJ(1, ColSJ);

char x = 206;
string X(1, x);

char tcd = 185;
string TD(1, tcd);

char tcs = 204;
string TS(1, tcs);

Caractere* Caractere::INStanta = NULL;
string Caractere::ColtDrJos = CDJ;
string Caractere::ColtDrSus = CDS;
string Caractere::ColtStJos = CSJ;
string Caractere::ColtStSus = CSS;
string Caractere::X = X;
string Caractere::TDr = TD;
string Caractere::TSt = TS;
string Caractere::Linie = L;
string Caractere::Coloana = C;
string Caractere::Perp = PERP;
Map* Map::instanta = NULL;