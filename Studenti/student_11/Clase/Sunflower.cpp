#include "Sunflower.h"
#include<iostream>
#include<string.h>
#include<Windows.h>
#include<iostream>
#include<fstream>
using namespace std;
Sunflower::Sunflower()
{
	health = 100;
	cost = 50;
}
Sunflower::~Sunflower()
{

}
void Sunflower::setPosition(int x, int y)
{
	ofstream logfile;
	logfile.open("log.exe");
	logfile << "Initializare sunflower...\n";
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD InputRecord;
	DWORD Events;
	COORD coord;
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 25;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hout, &cci);
	SetConsoleMode(hin, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	int t;
	t = 0;
	while (t!=1)
	{
			ReadConsoleInput(hin, &InputRecord,1, &Events);
			if (InputRecord.EventType == MOUSE_EVENT)
			{
				if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					SetConsoleCursorPosition(hout, coord);
					SetConsoleTextAttribute(hout, rand() % 7 + 9);
					cout << "S";
					t++;
				}
			}
		FlushConsoleInputBuffer(hin);
	}
}
int Sunflower::getCost()
{
	return this->cost;
}