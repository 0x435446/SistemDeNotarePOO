#include "Pea.h"

#define COL_DISTANCE_BETWEEN_PEAS	1

Pea::Pea(int putere):
	Proiectile(putere)
{
}

void Pea::ataca(int x,int y)
{
	
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = y+1;
	static std::string printedChar = "o";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 50)
	{
		begin = end;
		conOut(x, col) << printedChar;
		if (col >= y+1 + 100* COL_DISTANCE_BETWEEN_PEAS) {
			if (printedChar == "o")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "o";
			}
			col = y+1;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_PEAS;
		}
		
	}
}

Pea::~Pea()
{
}
