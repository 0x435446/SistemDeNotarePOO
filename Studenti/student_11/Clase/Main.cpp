#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include<stdlib.h>
#include "mapdraw.h"
#include "Main.h"
#include"Sunflower.h"
#include"Peashooter.h"
#include"Sun.h"
#include"zombie.h"
#include<thread>
#include<random>
#include<string>
#include<fstream>
#include<iostream>

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5
#define ROW_READY 22
#define COL_READY 75

using namespace std::chrono;
using namespace std;

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
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) 
		{
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
	string username;
	string password;
	cout << "Introduceti username-ul:";
	cin >> username;
	cout << username;
	cout << "\nIntroduceti parola:";
	cin >> password;
	cout << password;
	cout << "\nWelcome...";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	ofstream logfile;
	logfile.open("log.txt");
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	logfile << "Instantiere consola....\n";
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	logfile << "Instantiere input consola...\n";
	logfile << "Introducere username si parola...\n";
	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 173; j++)
			conOut(i, j) << " ";
	mapdraw* s = mapdraw::getInstance();
	Sunflower sunflower;
	Peashooter peashooter;
	Sun set;
	int random, col;
	zombie Zomb;
	random_device rd;
	mt19937 eng(rd());
	uniform_int_distribution<> distr(14, 20);
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	auto end = steady_clock::now();
	std::string action;
	int score = 100;
	logfile << "Inceput loading bar...\n";
		while (true)
		{
			
				doLoadingBar();
				action = conIn.getUserActions();
				if (action != "")
				{
					conOut(41, 2) << action;
				}

				if (duration_cast<seconds>(steady_clock::now() - end).count() > 3)
				{
					end = steady_clock::now();
					//system("CLS");
					break;
				}
		}
		logfile << "Creare harta...\n";
	//	system("CLS");
		for (int i = 0; i < 40; i++)
			for (int j = 0; j < 173; j++)
				conOut(i, j) << " ";
		s->scoreboardCreate(10, 10);
		conOut(10, 15) << "100";
		conOut(10, 16) << "0";
		s->suncaseCreate(10, 31);
		s->homeCreate(13, 28);
		s->laneCreate(13, 29);
		s->plantbuyzone(10, 48);
		conOut(20, 15) << "HOME";
		int counter1 = 0;
		int counter2 = 0;
		logfile.close();
		while (true)
		{
			/*if ((GetKeyState(VK_LBUTTON) & 0x80) != 0)
				break;*/
			set.setPosition(0,0);
			random = distr(eng);
			col = random;
				//std::thread(&zombie::setPosition, Zomb, random, 69).detach();
			action = conIn.getUserActions();
			if (action != "")
			{
				conOut(41, 2) << action;
			}
		} 
		
	return 0;
}
