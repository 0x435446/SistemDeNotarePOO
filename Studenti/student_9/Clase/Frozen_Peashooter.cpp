#include "Frozen_Peashooter.h"

Frozen_Peashooter::Frozen_Peashooter(int x, int y) {
	x_coord = x;
	y_coord = y;
}

Frozen_Peashooter::Frozen_Peashooter()
{
}


Frozen_Peashooter::~Frozen_Peashooter()
{
}

const void Frozen_Peashooter::print_entity()const {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	conOut(x_coord, y_coord) << char(239);
	conOut(x_coord - 1, y_coord) << char(195);
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}

const void Frozen_Peashooter::shoot_projectiles()const {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	int aux_y = y_coord;
	BattleField *bf; bf = bf->GetInstance();
	aux_y += 7;
	conOut(x_coord - 1, y_coord) << " ";
	if (aux_y < 96)
		conOut(x_coord - 1, aux_y) << "*";
}