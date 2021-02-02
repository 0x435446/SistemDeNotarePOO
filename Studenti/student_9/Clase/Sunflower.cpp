#include "Sunflower.h"

Sunflower::Sunflower(int x, int y) {
	x_coord = x;
	y_coord = y;
}

Sunflower::Sunflower()
{
}


Sunflower::~Sunflower()
{
}

const void Sunflower::print_entity()const {
	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED);
	conOut(x_coord, y_coord) << char(239);
	conOut(x_coord-1, y_coord) << char(206);
	conOut(x_coord-2, y_coord) << "*";
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

}

