#include"Board.h"
#include"ConsoleOutput.h"
using namespace UserInterface;

board::board()
{
	 UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	int i = 0, j = 0;
	for (i = 0; i < 36; i=i+6)
	{
		for (j = 0; j < 100; j++)
			conOut(i, j) << 95;
	}


}

