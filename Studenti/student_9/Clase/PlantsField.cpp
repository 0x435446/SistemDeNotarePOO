#include "PlantsField.h"



PlantsField::PlantsField()
{
}


PlantsField::~PlantsField()
{
}


const void PlantsField::print_field() const
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 10; i <= 35; i++) {
		conOut(i, 18) << "|";
		conOut(i, 28) << "|";
		if (i % 5 == 0) {
			for (int j = 18; j <= 28; j++) {
				conOut(i, j) << "-";
			}
		}
	}

	conOut(14, 19) << "Cost: 100";
	conOut(19, 19) << "Cost: 50";
	conOut(24, 19) << "Cost: 150";
	conOut(29, 19) << "Cost: 50";
	conOut(34, 19) << "Cost: 175";

	
	SetConsoleTextAttribute(console, FOREGROUND_GREEN);
	conOut(13, 23) << char(239);		//PeaShooter
	conOut(12, 23) << char(195);
	
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED);
	conOut(18, 23) << char(239);
	conOut(17, 23) << char(206);		//SunFlower
	conOut(16, 23) << "*";

	SetConsoleTextAttribute(console, FOREGROUND_RED);
	conOut(23, 22) << char(233) << " " << char(233);
	conOut(22, 23) << char(239);		//CherryBomb

	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	conOut(28, 23) << char(219);
	conOut(27, 23) << char(219);		//Wall-Nut

	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	conOut(33, 23) << char(239);		//IcePeaShooter
	conOut(32, 23) << char(195);
}
