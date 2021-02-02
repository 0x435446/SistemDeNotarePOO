#pragma once
#include<iostream>
#include<string.h>
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#define colt_stanga_sus 218
#define colt_stanga_jos 192
#define colt_dreapta_sus 191
#define colt_dreapta_jos 217
#define linie_orizontala 196
#define linie_verticala 179

using namespace std ;
class Map  
{
private:
	static Map *instance;
		unsigned int x, y;
		unsigned int lvl;
public:
	Map(int x ,int y,int lvl);
	~Map();
	static Map  *getInstance(int lvl);
	void doPatrat(int x, int y);
	void doPatrat1(int x, int y);
	void doPatrat2(int x, int y);
	void doHome(int x, int y);
	void drawSF();
	void drawPS();
};

