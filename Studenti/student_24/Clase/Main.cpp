#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <fstream>
#include <iostream>
#include <chrono>
#include "Entity.h"
#include "Map.h"
#include <vector>
#include "Resources.h"
#include "Sun.h"
#include "Score.h"
#include "Shop.h"
#include "Peashooter.h"
#include "Log.h"
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
	Log log;
	std::ofstream fout;
	fout.open("users.txt",std::ios_base::app);
	std::string name;
	std::string pasword;
	
	std::cout << "Username: ";
	std::cin >> name;
	std::cout << "Pasword: ";
	std::cin >> pasword;
	fout << name << ", " << pasword << std::endl;
	log.adaug_mesaj(name + "s-a logat");

	



	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	Score *scor = Score::getinstance();
	Shop *shop = Shop::getinstance();
	Resources *resource = Resources::getinstance();
	conOut(0, 0) << "                                              ";
	conOut(1, 0) << "                                              ";
	conOut(2, 0) << "                                              ";
	


	//conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	std::vector<Entity*> pup;
	pup.push_back(new Map);
	pup.push_back(resource);
	pup.push_back(shop);
	pup.push_back( scor);
	Peashooter pea;
	Parcela par;
	log.adaug_mesaj("jocul a inceput" );
	while (true) 
	{
		//doLoadingBar();
 		std::string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(41, 2) << action;
		}
		for (auto i : pup)
		{
			i->draw();
			i->uppdate(action);
		}
		
	

	}

	return 0;
}

