#pragma once
#define DIM_X 5
#define DIM_Y 12
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Sun.h"
#include "SunFlower.h"
#include "Zombi.h"
#include <chrono>
#include <vector>
class Teren
{private:
	Sun *SunArray[10];
	
	 char scena[DIM_X][DIM_Y];
	 UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	 UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
public:
	std::chrono::system_clock::time_point begin;
	Teren();
	void  afiseaza_scena();
	void printSun();
	void SunColect(std::string,Score&);
	void plant(std::string a, Score& score);
	void draw(std::string nextprocess, Plant *planta);
	
	~Teren();
};

