
#include "Interfata_LVL2.h"
#include "ConsoleOutput.h"

#define ColLenght 150
#define LinLenght 40
#define LinScore 0


void Interfata_LVL2::Layout_LVL2()
{
	for (int i = 9; i < 28; i++)
	{

		for (int j = 16; j <= ColLenght; j++)
		{


			if ((i + 3) % 6 == 0)
			{
				conOut(i, j) << "-";
			}
			if (j % 15 == 0)
				conOut(i, j) << "|";

		}
	}

}

Interfata_LVL2::Interfata_LVL2()
{
}

Interfata_LVL2::~Interfata_LVL2()
{
}