
#include "Interfata_LVL3.h"
#include "ConsoleOutput.h"

#define ColLenght 150
#define LinLenght 40
#define LinScore 0


void Interfata_LVL3::Layout_LVL3()
{
	for (int i = 4; i < 34; i++)
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

Interfata_LVL3::Interfata_LVL3()
{
}

Interfata_LVL3::~Interfata_LVL3()
{
}