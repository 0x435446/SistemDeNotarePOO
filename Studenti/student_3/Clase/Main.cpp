#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "draw.h"
#include "sunManagement.h"
#include <time.h>
#include "buget.h"
#include "sunflower.h"
#include "zombie.h"
#include <conio.h>
#include <chrono>
#include <string>
#include <iostream>


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

bool esteGol(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

void salvareUser(const char *text)
{

	std::ifstream fin("user.log");

	bool flag = false;

	if (esteGol(fin))
		flag = true;

	fin.close();

	if (flag)
	{
		std::fstream fout("user.log", std::fstream::out);
		fout << text << std::endl;
		fout.close();
	}
	else
	{
		std::fstream fapp("user.log", std::fstream::app);
		fapp << text << std::endl;
		fapp.close();
	}

}


int main(void)
{
	std::string buffer;
	std::cout << "Introduceti un username:";
	std::cin >> buffer;
	salvareUser(buffer.c_str());
	system("cls");

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();


	std::vector<zombie*> vectorZombie;


	bool flag = false;
	int x = 170, y = 25;
	while(flag != true)
		{

			conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
			doLoadingBar();
			if (_kbhit())
				flag = true;
		}

	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "                                                    ";

	
		//for (i = 0; i < 10; i++)
		//{
		//	for (j = y; j <y + 10; j++)
		//		conOut(20 + i, 20 + j) << "*";
		//	//conOut(20+i, 20 + j) << "\n";
		//}
		//Sleep(600);
		//for (i = 0; i < 10; i++)
		//{
		//	for (j = y; j <y + 10; j++)
		//		conOut(20 + i, 20 + j) << " ";
		//	//conOut(20+i, 20 + j) << "\n";
		//}
		//y++;
		//if (y > 120)
		//	y = 1;


	//aici se introduce nivelul
	//pentru intelegere, l-am lasat pe nivelul de dificultate 1
	draw Plansa;
	Plansa.drawStaticTable(1);

	while (true)
	{
		static auto begin = steady_clock::now();
		auto end = steady_clock::now();
		if (duration_cast<milliseconds>(end - begin).count() > (7000 / sunflower::getNrSunflower()))
		{
			begin = end;
			sunManagement::getInstance().addSun();
			buget::getBuget().addBani(100);
		}
		std::string action = conIn.getUserActions();
		conOut(4, 7) << buget::getBuget().getBani();

		static auto begin2 = steady_clock::now();
		auto end2 = steady_clock::now();
		if (duration_cast<milliseconds>(end2 - begin2).count() > 8000)
		{
			begin2 = end2;
			zombie *zom = new zombie(y, x);
			zom->drawZombie(y, x);
			vectorZombie.push_back(zom);
		}

		static auto begin3 = steady_clock::now();
		auto end3 = steady_clock::now();
		if (duration_cast<milliseconds>(end3 - begin3).count() > 700)
		{
			begin3 = end3;
			for (auto it = vectorZombie.begin(); it != vectorZombie.end(); it++)
			{
				
				(*it)->stergereZombie((*it)->getX(), (*it)->getY());
				for (auto it2 = conIn.vectorPlante.begin(); it2 != conIn.vectorPlante.end(); it2++)
				{
					if ((*it2)->getLife() == 0)
					{
						(*it2)->setDead();
						(*it)->setZombieSpeed(5);
					}
					if (((*it)->getY() - (*it)->getZombieSpeed()) == ((*it2)->getY()))
						(*it2)->setLife((*it)->fightWith((*it2)->getNume(), (*it2)->getLife()));
					else
					{
						(*it)->setZombieSpeed(5);
					}
				}
				(*it)->setX((*it)->getY() - (*it)->getZombieSpeed());
				(*it)->drawZombie((*it)->getX(), (*it)->getY());
			}
		}

		if (duration_cast<milliseconds>(end - begin).count() > 10)
		{

			for (auto it = vectorZombie.begin(); it != vectorZombie.end(); it++)
			{
				if ((*it)->getDead() == true)
					(*it)->stergereZombie((*it)->getX(), (*it)->getY());
				if ((*it)->getY() < 20)
					exit(0);
			}

			for (auto it2 = conIn.vectorPlante.begin(); it2 != conIn.vectorPlante.end();)
			{
				if ((*it2)->getDead() == true)
				{
					(*it2)->deleteSunflower((*it2)->getX(), (*it2)->getY());
					(*it2)->setActive();
					delete (*it2);
					it2 = conIn.vectorPlante.erase(it2);
				}
				else
				{
					++it2;
				}
			}

			if (action != "")
			{
				conOut(48, 2) << action;
			}
		}
	}


	getchar();
	return 0;
}

