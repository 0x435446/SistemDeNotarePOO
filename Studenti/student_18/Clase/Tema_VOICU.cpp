#include <time.h>
#include <chrono>
#include"ConsoleInput.h"
#include"ConsoleOutput.h"
#include"GameEngine.h"
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
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	for (auto start = std::chrono::steady_clock::now(), now = start; now < start + std::chrono::seconds{ 1 }; now = std::chrono::steady_clock::now()) {   //functie care dureaza 1 secunda
		doLoadingBar();
	}
	system("cls");


	GameEngine& gameEngine = GameEngine::GetInstance();
	gameEngine.start();

	return 0;
}