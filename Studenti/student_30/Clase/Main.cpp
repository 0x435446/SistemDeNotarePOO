#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <fstream>
#include <chrono>
#include<conio.h>
#include "Zona.h"
#include "Ground.h"
#include "Resurse.h"
#include "Plant.h"
#include "Sunflower.h"
#include "Scor.h"
#include "Zombie.h"


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
	std::string name;
	std::string parola;
	std::ofstream fout;
	fout.open("Users.txt", std::ios_base::app);
	std::cout << "Introduceti username-ul:";
	std::cin >> name;
	std::cout << "Introduceti parola:";
	std::cin >> parola;
	system("cls");
    fout << name << "-" << parola << std::endl;
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	conOut(41, 143) << "Username: "<<name;
	std::vector<Entity*> vect;
	vect.push_back(new Ground(20,15));
	vect.push_back(new Ground(8, 15));
	vect.push_back(new Ground(15, 15));
	vect.push_back(new Ground(27, 15));
	vect.push_back(new Ground(34, 15));
	vect.push_back(new Resurse(0, 13));
	vect.push_back(new Plant(8, 2));
	vect.push_back(new Scor(0, 1));
	Scor *scor = Scor::getInstance();
	vect.push_back(scor);
	
	while (true)
	{
		std::string action = conIn.getUserActions();
		for (auto it : vect)
		{
			it->draw();
			it->update(action);
		}
		if (action != "")
		{
			conOut(41, 2) << action;
		}
		
	}
	_getch();
	return 0;
}