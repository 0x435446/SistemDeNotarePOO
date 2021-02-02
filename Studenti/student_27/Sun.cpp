#include "Sun.h"

Sun::Sun()
{
	numberSun = 0;
	sunRow=0;
	sunCol = 0;
	sunWait = 7000;
}

Sun::~Sun()
{
}

void Sun::CheckForSun(std::string action)
{
	char* sentence = new char[512];

	strcpy(sentence, action.c_str());

	char* token = strtok(sentence, " ");

	int x = 1;

	int ok = 0;

	while (token)
	{
		if (x == 4 && strcmp(token, "double") == 0)
		{
			ok = 1;
		}
		x++;
		token = strtok(NULL, " ");
	}

	if (ok == 1)
	{
		int xPos;
		int yPos;

		char posX[10];
		char posY[10];

		int OK = 0;

		int i = 0;

		while (OK == 0)
		{
			if (action[i] == '(')
			{
				int j = i + 1;

				int k = 0;

				while (action[j] != ',')
				{
					posX[k] = action[j];
					j++;
					k++;
				}
				posX[k] = '\0';
				yPos = atoi(posX);
				k = 0;

				while (action[j] != ')')
				{
					int ok = 0;

					if (action[j] != ' ' && action[j] != ',')
					{
						posY[k] = action[j];
						k++;
						j++;
						ok = 1;
					}
					posY[k] = '\0';
					if (ok == 0)
						j++;
				}
				xPos = atoi(posY);
				OK = 1;
			}
			i++;
		}

		if (xPos == sunRow && yPos == sunCol)
		{
			COORD coord;
			coord.X = sunCol;
			coord.Y = sunRow;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			std::cout << " ";
			sunRow = 0;
			sunCol = 0;
			numberSun = numberSun + 50;

			for (int m = 3; m <= 5; m++)
			{
				coord.X = m;
				coord.Y = 3;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				std::cout << " ";
			}
			coord.X = 3;
			coord.Y = 3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			std::cout << numberSun;
		}

	}

}

void Sun::CheckForSun(int xPos, int yPos)
{
	if (xPos == sunRow && yPos == sunCol)
	{
		COORD coord;
		coord.X = sunCol;
		coord.Y = sunRow;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout << " ";
		sunRow = 0;
		sunCol = 0;
		numberSun = numberSun + 50;
		this->SetSun();
	}
}

void Sun::ReduceTimeToWait()
{
	sunWait = sunWait - 1000;
}

int Sun::GetSunRow()
{
	return sunRow;
}

int Sun::GetSunCol()
{
	return sunCol;
}

int Sun::GetSunWait()
{
	return sunWait;
}

void Sun::SetSunRow(int row)
{
	sunRow = row;
}

void Sun::SetSunCol(int col)
{
	sunCol = col;
}

int Sun::GetNumberSun()
{
	return numberSun;
}

void Sun::ReduceNumberSun(int number)
{
	numberSun = numberSun - number;
}

void Sun::SetSun()
{
	COORD coord;

	for (int m = 3; m <= 5; m++)
	{
		coord.X = m;
		coord.Y = 3;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout << " ";
	}
	coord.X = 3;
	coord.Y = 3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << numberSun;
}
