#include "Peashooter.h"



Peashooter::Peashooter(int x, int y)
{
	x_coord = x;
	y_coord = y;
}


Peashooter::~Peashooter()
{
}

const void Peashooter::print_entity() const
{	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	SetConsoleTextAttribute(console, FOREGROUND_GREEN);
	conOut(x_coord, y_coord) << char(239);	
	conOut(x_coord-1, y_coord) << char(195);
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}

const void Peashooter::shoot_projectiles() const
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static int aux_y = y_coord;
	BattleField *bf; bf = bf->GetInstance();
	if (aux_y != y_coord)
		conOut(x_coord - 1, aux_y) << " ";
	aux_y += 7;
	if (aux_y < 96)
		conOut(x_coord-1, aux_y) << "*";
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	

}
