#include "draw.h"
#include <Windows.h>
#include "buget.h"
#include "Log.h"
#define SCOR_X 1
#define SCOR_Y 1
#define BUGET_X 1
#define BUGET_Y 4


draw::draw()
{
}


draw::~draw()
{
}

void draw::drawStaticTable(int level)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED);

//coord
//3, 11
//3, 18
	conOut(SCOR_Y, SCOR_X) << "SCOR:";
	conOut(BUGET_Y, BUGET_X) << "BUGET:";
	conOut(11, 3) << "Sunflower";
	conOut(18, 3) << "Peashooter";

	Log::getInstance().displayMessage("Creare chenar.");
	//prima + ultima bara orizontala lunga
	if (level != 3)
	{
		for (int i = 0; i < 180; i++)
		{
			if (i != 20)
			{
				conOut(7, i) << "-";
				conOut(42, i) << "-";
			}
		}
	}

	//prima + ultima bara verticala lunga
	for (int i = 0; i < 43; i++)
	{
		conOut(i, 20) << "|";
		conOut(i, 180) << "|";
	}

	//grid pe orizontala
	for (int i = 7; i < 47; i = i + 7)
		for (int j = 0; j < 20; j++)
			conOut(i, j) << "-";

	//grid pe verticala
	for (int i = 0; i < 7; i++)
	{
		for (int j = 40; j < 180; j += 20)
			conOut(i, j) << "|";
	}

	if (level == 1)
	{
		//bara orizontala 1   -----><21, 21>
		//bara orizontala 2   -----><21, 28>
		for (int i = 21; i < 180; i++)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN);
			conOut(21, i) << "-";
			conOut(28, i) << "-";
		}
		//TODO: pe culoarul din mijloc
	}

	if (level == 2)
	{
		//TODO 3 randuri pe mijloc
		for (int i = 21; i < 180; i++)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN);
			conOut(14, i) << "-";
			conOut(21, i) << "-";
			conOut(28, i) << "-";
			conOut(35, i) << "-";
		}
	}

	if (level == 3)
	{
		//TODO tot tabelul plin
		for (int i = 21; i < 180; i++)
		{
			SetConsoleTextAttribute(h, FOREGROUND_GREEN);
			conOut(7, i) << "-";
			conOut(14, i) << "-";
			conOut(21, i) << "-";
			conOut(28, i) << "-";
			conOut(35, i) << "-";
			conOut(42, i) << "-";
		}
	}

}

