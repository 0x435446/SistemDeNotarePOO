#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include"Teren.h"
#include"sun.h"
#include <time.h>
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include"score.h"
#include<vector>


#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

using namespace std::chrono;

void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
			if (printedChar == "*")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "*";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_STARS;
		}		
	}
}

int main(void)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Plants vs Zombie";
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION) << "                  ";
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	auto begin = std::chrono::steady_clock::now();
	auto end = std::chrono::steady_clock::now();
	
	while (std::chrono::duration_cast<seconds>(end-begin).count()<3)
	{
		
		end = std::chrono::steady_clock::now();
		doLoadingBar();
		std::string action = conIn.getUserActions();
		if (action != "")
		{

			conOut(41, 2) << action;
		}

		
	}
	conOut(0, 0);
	Teren scena;
	/*COORD num;
	sun s;
	s.setcord(2, 4);
	num = s.getcord();
	s.afiseaza(num);*/

	score p;

	
	while (true)
	{
		
		scena.afiseaza_scena();
		std::vector<sun*>light;
		sun* buff = new sun();
		light.push_back(buff);
		//sun afiseaza(COORD num);
		//conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Plants vs Zombie";
		std::string action = conIn.getUserActions();
		if (action != "")
		{

			conOut(41, 2) << action;
		}
	}
	return 0;
}

