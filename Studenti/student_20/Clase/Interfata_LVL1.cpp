
#include "Interfata_LVL1.h"
#include "ConsoleOutput.h"

#define ColLenght 150
#define LinLenght 40
#define LinScore 0


void Interfata_LVL1::Layout_LVL1()
{
	for (int i = 15; i < 22; i++)
	{

		for (int j = 16; j <= ColLenght; j++)
		{


			if ((i + 3) % 6 == 0)
			{
				conOut(i, j) << "-";
			}
			if (j%15== 0)
				conOut(i, j) << "|";

		}
	}

}

Interfata_LVL1::Interfata_LVL1()
{
}

Interfata_LVL1::~Interfata_LVL1()
{
}
