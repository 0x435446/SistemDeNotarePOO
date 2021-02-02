#include "Potato.h"

Potato::Potato(int x, int y) {
	x_coord = x;
	y_coord = y;
}

Potato::Potato()
{
}


Potato::~Potato()
{
}

const void Potato::print_entity() const {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	conOut(x_coord, y_coord) << char(219);
	conOut(x_coord-1, y_coord) << char(219);
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}
