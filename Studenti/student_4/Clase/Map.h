#pragma once
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include <time.h>
#include <iostream>
#include "Caractere.h"
#include "Consola.h"
using namespace std;


class Map
{
private:
	static Map* instanta;
	Map() {};

public:

	static Map* SetInstanta();
	static void Afis();
	static void Linia_1();

	static void Mapa();

	/*static void Coloana();*/
};

