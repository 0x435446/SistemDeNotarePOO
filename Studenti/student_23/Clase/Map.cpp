#include "Map.h"

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5
#define MAX_ROW 40
#define MAX_COL 150
#define ROW_SCORE 1
#define COL_SCORE 6
#define ROW_FIRST_TILE 4
#define COL_FIRST_TILE 16
#define TILE_SIZE_ROW 6

using namespace std::chrono;

Map::Map()
{
	this->conOut = UserInterface::ConsoleOutput::getInstance();
	this->conIn = UserInterface::ConsoleInput::getInstance();
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	while (true)
	{
		doLoadingBar();
		std::string action = conIn.getUserActions();
		if (action.compare("keyEvent") == 0) {
			clearScreen();
			break;
		}
		if (action != "")
		{
			conOut(41, 2) << action;
			conOut(41, 75) << "Press any key to continue";
		}

	}
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			field[i][j] = '0';
		}
	}

}

void Map::doLoadingBar()
{

	this->conOut = UserInterface::ConsoleOutput::getInstance();
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

void Map::clearScreen()
{
	system("cls");
	this->conIn = UserInterface::ConsoleInput::getInstance();
	this->conOut = UserInterface::ConsoleOutput::getInstance();
}

void Map::gameOver()
{
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "You have lost the game.";
}

void Map::drawTiles(int level, int score)
{
	conOut(ROW_SCORE, 0) << "Score:" << score;
	conOut(ROW_SCORE + 1, 0) << "Suns:0";
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j <= MAX_COL; j++) {
			if (i == 3 && j % 15 == 0) {
				conOut(i, j) << '+';
			}
			else {
				if (j % 15 == 0) {
					conOut(i, j) << '|';
				}
				if (i == 3) {
					conOut(i, j) << '-';
				}
			}
			if (i == 0 && j <= 15) {
				conOut(i, j) << "-";
			}
		}
	}
	conOut(3, 0) << "-";

	for (int i = 4; i < MAX_ROW - 6; i++) {

		for (int j = 0; j <= MAX_COL; j++) {


			if ((i + 3) % 6 == 0) {
				conOut(i, j) << "-";
			}
			if (j == 15)
				conOut(i, j) << "|";

		}
	}

	conOut(6, 3) << "Sunflower";
	conOut(7, 6) << "50";
	conOut(12, 3) << "PeaShooter";
	conOut(13, 6) << "100";
	conOut(18, 4) << "Wallnut";
	conOut(19, 6) << "150";


	switch (level)
	{
	case 1:
		for (int i = ROW_FIRST_TILE + TILE_SIZE_ROW; i < MAX_ROW - 6; i++) {
			for (int j = COL_FIRST_TILE; j <= MAX_COL; j++) {
				if ((i + 3) % 6 != 0)
					conOut(i, j) << "\\";
			}
		}
		break;
	case 2:
		for (int i = ROW_FIRST_TILE + (3 * TILE_SIZE_ROW); i < MAX_ROW - 6; i++) {
			for (int j = COL_FIRST_TILE; j <= MAX_COL; j++) {
				if ((i + 3) % 6 != 0)
					conOut(i, j) << "\\";
			}
		}
		break;

	}
}

void Map::drawSunshine(int nr)
{
	conOut(2, (15 * nr) + 4) << "Sunshine";
}

void Map::deleteSunshine(int nr)
{
	conOut(2, (15 * nr) + 4) << "        ";
}

int Map::drawPlant(int X, int Y, char character)
{
	int linie=0;
	if (Y < 9) {
		linie = 1;
	}
	else if (Y < 15) {
		linie = 2;
	}
	else if (Y < 21) {
		linie = 3;
	}
	else if (Y < 27) {
		linie = 4;
	}
	else if (Y < 33) {
		linie = 5;
	}
	if (this->field[linie*6][X] == '0') {

		this->field[linie*6][X] = character;
		conOut(linie*6, X) << character;
		return (linie*6);
	}
	return 0;
}

void Map::drawZombie(int X, int Y, char character)
{
	conOut(Y, X + 1) << ' ';
	conOut(Y, X)<<character;
	
}

void Map::drawProjectile(int X, int Y,char character)
{
	if (this->field[Y][X-1] == '0') {
		conOut(Y, X-1) << ' ';
	}
	conOut(Y, X) << character;
}

void Map::userAction()
{

	std::string action = conIn.getUserActions();
	if (action != "")
	{

		conOut(41, 2) << action;

	}

}

int Map::checkCoords(int X, int Y)
{
	//Verifica la soare
	if (Y < 3 && X>15)
		return 1;
	else if (Y > 3) {
		//Verifica la Sunflower
		if (Y < 9 && X < 15)
			return 2;
		//Verifica PeaShooter
		else if (Y < 15 && X < 15)
			return 3;
		//Verifica Wallnut
		else if (Y < 21 && X < 15)
			return 4;
		//Verifica daca e pe camp
		else if (Y > 5 && Y < MAX_ROW - 6 && X <= MAX_COL)
			return 5;
	}



	return 0;
}

void Map::updateMoney(int bani)
{
	conOut(2, 5) << "     ";
	conOut(2, 5) << bani;
}

int Map::testField(int X, int Y)
{
	if (field[X][Y] != '0')
		return 1;
	return 0;
}

void Map::tester(std::string test)
{
	char test_in;
	conOut(MAX_ROW, 0) << test;
	conOut(MAX_ROW, 2);
}
