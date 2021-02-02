#include <vector>
#include <time.h>
#include <windows.h>

#include "Calcule.h"

void Calcule::InitSunVector()
{
	for (int i = 0; i < 9; i++)
		vector_soare.push_back(0);
}

int Calcule::CheckInputPlante(int x, int y, int& Select)
{
	if (y >= 4 && y <= 9 && this->Sun >= 50)// select sunflower
	{
		this->Sub_Sun(50);
		Select = 1;
		return 1;
	}

	if (y >= 10 && y <= 15 && this->Sun >= 100)// pea
	{
		this->Sub_Sun(100);
		return 2;
	}

	if (y >= 16 && y <= 21 && this->Sun >= 150)// wall	
	{
		this->Sub_Sun(150);
		return 3;
	}
}
void Calcule::CheckInputSoare(int x, int y)
{
	if (x >= 16 && x <= 29 && vector_soare[0] == 1)
		{
			this->Add_Sun();
			vector_soare[0] = 0;
			conOut(1, (0 + 2) * 15 - 9) << "   ";
			this->NumSun--;
		}
	if (x >= 31 && x <= 44 && vector_soare[1] == 1)
		{
			this->Add_Sun();
			vector_soare[1] = 0;
			conOut(1, (1 + 2) * 15 - 9) << "   ";
			this->NumSun--;
		}
	if (x >= 46 && x <= 59 && vector_soare[2] == 1)
		{
			this->Add_Sun();
			vector_soare[2] = 0;
			conOut(1, (2 + 2) * 15 - 9) << "   ";
			this->NumSun--;
		}
	if (x >= 61 && x <= 74 && vector_soare[3] == 1)
		{
			this->Add_Sun();
			vector_soare[3] = 0;
			conOut(1, (3 + 2) * 15 - 9) << "   ";
			this->NumSun--;
		}
	if (x >= 76 && x <= 89 && vector_soare[4] == 1)
		{
			this->Add_Sun();
			vector_soare[4] = 0;
			conOut(1, (4 + 2) * 15 - 9) << "   ";
			this->NumSun--;
		}
	if (x >= 91 && x <= 104 && vector_soare[5] == 1)
		{
			this->Add_Sun();
			vector_soare[5] = 0;
			conOut(1, (5 + 2) * 15 - 9) << "   ";
			this->NumSun--;
		}
	if (x >= 106 && x <= 119 && vector_soare[6] == 1)
		{
			this->Add_Sun();
			vector_soare[6] = 0;
			conOut(1, (6 + 2) * 15 - 9) << "   ";
			this->NumSun--;
		}
	if (x >= 121 && x <= 134 && vector_soare[7] == 1)
		{
			this->Add_Sun();
			vector_soare[7] = 0;
			conOut(1, (7 + 2) * 15 - 9) << "   ";
			this->NumSun--;
		}
	if (x >= 136 && x <= 149 && vector_soare[8] == 1)
		{
			this->Add_Sun();
			vector_soare[8] = 0;
			conOut(1, (8 + 2) * 15 - 9) << "   ";
			this->NumSun--;
		}
	conOut(2, 0) << "Sun:" << this->Sun;

	
}

void Calcule::DrawSun()
{
	srand(time(NULL));
	int p = rand() % 9;
	while (vector_soare[p] != 0)
		p = rand() % 9;
	vector_soare[p] = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	conOut(1, (p + 2) * 15 - 9) << "SUN";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Calcule::DrawPeaShooter(int x,int y)
{
	conOut(x,y) << "Peashooter";
}
void Calcule::DrawSunFlower(int x, int y)
{
	conOut(x, y) << "Sunflower";
}
void Calcule::DrawWallNut(int x, int y)
{
	conOut(x, y) << "Wallnut";
}
Calcule::Calcule()
{
}

Calcule::~Calcule()
{
}
