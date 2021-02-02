#pragma once
#define DIM_X 5
#define DIM_Y 12
#include"ConsoleInput.h"
#include"ConsoleOutput.h"
#include<chrono>
class Teren
{
public:
	std::chrono::system_clock::time_point begin;
	Teren();
	~Teren();
	void afiseaza_scena();

private:
	char scena[DIM_X][DIM_Y];
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	
};

