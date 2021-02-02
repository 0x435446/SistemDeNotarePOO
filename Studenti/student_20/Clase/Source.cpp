#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <vector>

#include "DoubleClick.h"
#include "Utilizator.h"
#include "Interfata.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Calcule.h"

#define LinScore 0
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

int main()
{
	Interfata D;

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	while (true)
	{
		doLoadingBar();
		std::string action = conIn.getUserActions();
		if (action.compare("Action") == 0)
		{
			D.Clscr();
			break;
		}

		if (action != "")
		{

			conOut(41, 2) << action;
		}
	}
	D.GetName();
	D.GetDifficulty();
	D.ChooseLayout();

	Calcule R;
	
	int X = 0;
	int Y = 0;
	int NRCLICK = 0;
	int Select = 0;
	
	auto Begin = std::chrono::steady_clock::now();
	R.InitSunVector();

	bool PlayGame = true;
	conOut = UserInterface::ConsoleOutput::getInstance();
	 conIn = UserInterface::ConsoleInput::getInstance();
	while (PlayGame)
	{
		
		DoubleClick::getInstance();
		std::string action = conIn.getUserActions();
		if (action != "")
		{

			conOut(41, 2) << action;
		}
		if (DoubleClick::getNrClicks() > NRCLICK)
		{
			DoubleClick::getCoords1(X, Y);

			conOut(40, 2) <<X<<' '<<Y;
			if (Y >= 0 && Y <= 3) R.CheckInputSoare(X, Y);

			if (X >= 0 && X <= 14 && Select == 0)
			{
				
				int TipPlanta = R.CheckInputPlante(X, Y, Select);
				DoubleClick::setNrClicks(0);
				switch (TipPlanta)
				{
				case(1):
					if (DoubleClick::getNrClicks() > NRCLICK)
						DoubleClick::getCoords2(X, Y);
					R.DrawSunFlower(X,Y);
					Select = 0;
					break;
				case(2):
					if (DoubleClick::getNrClicks() > NRCLICK)
						DoubleClick::getCoords2(X, Y);
					R.DrawPeaShooter(X, Y);
					Select = 0;
					break;
				case(3):
					if (DoubleClick::getNrClicks() > NRCLICK)
						DoubleClick::getCoords2(X, Y);
					R.DrawWallNut(X, Y);
					Select = 0;
					break;
				default:
					break;

				}
				
				conOut(2, 0) << "Sun:" << R.Sun<<"    ";

			}
		}
		auto End = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(End - Begin).count() >= R.GetTime() && R.NumSun < 9)
		{
			Begin = End;
			R.NumSun++;
			R.DrawSun();
		}
		



	}



}