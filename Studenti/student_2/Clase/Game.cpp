#include "Game.h"
#include "Teren.h"
#include "Score.h"
#include <time.h>
#include <chrono>
#include <conio.h>

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		55
#define COL_DISTANCE_BETWEEN_STARS	3

using namespace std::chrono;
Game::Game()
{
	doLoadingBar();
	play();

}

void Game::doLoadingBar()
{

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

void Game::play()
{
		
		conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading game...";
		auto begin = std::chrono::steady_clock::now();
		auto end = std::chrono::steady_clock::now();

		while (std::chrono::duration_cast<seconds>(end - begin).count() < 3)
		{
			end = std::chrono::steady_clock::now();
			doLoadingBar();
			std::string action = conIn.getUserActions();
			if (action != "")
			{
				conOut(41, 2) << action;
			}
		}
		conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Plants vs Zombie";
		conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION) << "                 ";

		begin = std::chrono::steady_clock::now();
		end = std::chrono::steady_clock::now();
		while (std::chrono::duration_cast<seconds>(end - begin).count() < 2)
		{
			end = std::chrono::steady_clock::now();
			std::string action = conIn.getUserActions();
			if (action != "")
			{
				conOut(41, 2) << action;

			}
		}
		conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "                 ";
		conOut(0, 0);
		int time = 0;
		Teren scena;
		Score Scoreboard;
		while (true)
		{
		
			if (time % 10000 == 0)
			{
				int x = rand() % 5 + 1;
				int a = (x * 5) + 2;
				int b = 110;
				Zombie *z1 = new Zombi(a, b);
				monster.push_back(z1);
				Sleep(100);
			}

			time++;
			std::string action = conIn.getUserActions();
			scena.printSun();
			scena.SunColect(action, Scoreboard);
			scena.plant(action, Scoreboard);
			if (time % 1000 == 0)
			{
				move_zom();
				Sleep(20);
			}
			if (action != "")
			{
				conOut(41, 2) << action;

			}

		}
		Sleep(6000);
}

void Game::move_zom()
{
	for (auto it = monster.begin(); it != monster.end(); it++)
	{
		(*it)->move();
		
	}
}
Game::~Game()
{
}
