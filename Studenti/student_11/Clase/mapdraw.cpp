#include "mapdraw.h"
#include<iostream>
#include<string>
#include"ConsoleInput.h"
#include"ConsoleOutput.h"
using namespace std;
mapdraw* mapdraw::instance = 0;
mapdraw* mapdraw::getInstance()
{
	if (instance == 0)
	{
		instance = new mapdraw();
	}

	return instance;
}
UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
mapdraw::mapdraw()
{}
mapdraw::~mapdraw()
{}
void mapdraw::scoreboardCreate(int x, int y)
{
	int r, c;
	for (r = 0; r < 4; ++r)
	{
		for (c = 0; c < 20; ++c)
		{
			if (r == 0 || r == 3)
				conOut(r + x-1, c + y-1) << "-";
			else
			{
				if (c == 0 || c == 19)
					conOut(r + x-1, c + y-1) << "|";
				else
					conOut(r + x-1, c + y-1) << " ";
			}
		}
		cout << endl;
	}
	conOut(x, y) << "Sun : ";
	conOut(x+1, y) << "Score: \n";
}

void mapdraw::suncaseCreate(int x, int y)
{
	int r, c;
	for (r = 0; r < 3; ++r)
	{
		for (c = 0; c < 9; ++c)
		{
			if (r == 0 || r == 2)
				conOut(r + x - 1, c + y - 1) << "-";
			else
			{
				if (c == 0||c%2==0||c==8)
					conOut(r + x - 1, c + y - 1) << "|";
				else
					conOut(r + x - 1, c + y - 1) << " ";
			}
		}
		cout << endl;
	}
}

void mapdraw::homeCreate(int x, int y)
{
	for (int i = 0; i <= 8; i++)
		conOut(x+i, y) << "|";
}

void mapdraw::laneCreate(int x, int y)
{
	for (int i = 0; i < 9; i+=2)
	{
		for (int j = 0; j < 40; j++)
		{
			conOut(x + i, y + j) << "-";
		}
		conOut<< "|";
	}
}

void mapdraw::plantbuyzone(int x, int y)
{
	int r, c;
	for (r = 0; r < 3; ++r)
	{
		for (c = 0; c < 9; ++c)
		{
			if (r == 0 || r == 2)
				conOut(r + x - 1, c + y - 1) << "-";
			else
			{
				if (c == 0 || c % 2 == 0 || c == 8)
					conOut(r + x - 1, c + y - 1) << "|";
				else
					conOut(r + x - 1, c + y - 1) << " ";
			}
		}
		cout << endl;
	}
	conOut(10, 48) << "S";
	conOut(10, 50) << "P";
}
