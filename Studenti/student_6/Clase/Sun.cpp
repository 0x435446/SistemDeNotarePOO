#define _CRT_SECURE_NO_WARNINGS
#include "Sun.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Coordonate.h"
#include <time.h>
#include <chrono>
#define ROW_SUN					2			
#define COL_FIRST_SUN_POSITION		24
#define COL_DISTANCE_BETWEEN_SUNS	30

using namespace std::chrono;

Sun::Sun():
	Resurse()
{
}

void Sun::set_location(Teren &t,int rate)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_SUN_POSITION;
	static std::string printedChar = "#";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > rate)
	{
		begin = end;
		conOut(ROW_SUN + 1, col) << printedChar;
		if (col >= COL_FIRST_SUN_POSITION + 4 * COL_DISTANCE_BETWEEN_SUNS) {
			if (printedChar == "#")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "#";
			}
			col = COL_FIRST_SUN_POSITION;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_SUNS;
		}
	}
}


void Sun::colectare_sori(Teren t,int x,int y)
{
	Log::get_instance().logevent("Se colecteaza resurse\n");
	t.gotoXY(x, y);
	printf(" ");
}

Sun::~Sun()
{
}
