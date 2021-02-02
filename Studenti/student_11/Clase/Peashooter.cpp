#include "Peashooter.h"
#include<iostream>
#include<string.h>
#include<Windows.h>
#include"ConsoleOutput.h"
#include<fstream>
using namespace std;
Peashooter::Peashooter()
{
	health = 100;
	cost = 100;
}
Peashooter::~Peashooter()
{

}
void Peashooter::setPosition(int x, int y)
{
	ofstream logfile;
	logfile.open("log.txt");
	logfile << "Initializare peashooter...\n";
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD InputRecord;
	DWORD Events;
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 25;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hout, &cci);
	SetConsoleMode(hin, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	int t;
	t = 0;
	while (t != 1)
	{
			ReadConsoleInput(hin, &InputRecord, 1, &Events);
			if (InputRecord.EventType == MOUSE_EVENT)
			{
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					//coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					x = InputRecord.Event.MouseEvent.dwMousePosition.X;
					this->x = x;
					//coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					this->y = y;
					/*SetConsoleCursorPosition(hout, coord);
					SetConsoleTextAttribute(hout, rand() % 7 + 9);*/
					conOut(y,x) << "P";
					t++;
				}
			}
		FlushConsoleInputBuffer(hin);
	}
}
int Peashooter::getX()
{
	return this->x;
}
int Peashooter::getY()
{
	return this->y;
}

int Peashooter::getCost()
{
	return this->cost;
}
