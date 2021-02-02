#include "sunflower.h"
#include "Log.h"
#include "ConsoleOutput.h"

int sunflower::numarSunflower = 1;

sunflower::sunflower(int x, int y)
{
	this->nume = "sunflower";
	pos_x = x;
	pos_y = y;
	lifePoints = 20;
	dead = false;
	activ = true;
	attackPoints = 0;
	Log::getInstance().displayMessage("Creare sunflower.\n");
	sunflower::numarSunflower += 1;
}

void sunflower::drawSunflower(int x, int y)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	//+4 in jos +6 laterala
	conOut(x + 4, y + 6) << "sunflower";
	return;
}

void sunflower::deleteSunflower(int, int)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->pos_x + 4, this->pos_y +6) << "         ";
}

int sunflower::fightWith(std::string nume, int life)
{
	return 0;
}


sunflower::~sunflower()
{
	this->activ = false;
	Log::getInstance().displayMessage("Stergere sunflower.\n");
}
