#include "Cherrybomb.h"

Cherrybomb::Cherrybomb(int x, int y) {
	x_coord = x;
	y_coord = y;
}

Cherrybomb::Cherrybomb()
{
}


Cherrybomb::~Cherrybomb()
{
}

const void Cherrybomb::print_entity()const {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	SetConsoleTextAttribute(console, FOREGROUND_RED);
	conOut(x_coord, y_coord) << char(233) << " " << char(233);
	conOut(x_coord - 1, y_coord + 1) << char(239);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	conOut(x_coord, y_coord) << "   ";
	conOut(x_coord - 1, y_coord + 1) << "bo";
	conOut(x_coord, y_coord + 1) << "om";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	conOut(x_coord - 1, y_coord + 1) << "  ";
	conOut(x_coord, y_coord + 1) << "  ";
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}

