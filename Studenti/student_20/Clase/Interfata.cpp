#include <iostream>
#include <windows.h>
#include <time.h>

#include "Interfata.h"



#define ColLenght 150
#define LinLenght 40
#define LinScore 0

void Interfata::Clscr()
{
	system("cls");
	this->conIn;
	this->conOut;
}

void Interfata::SetDifficulty(int Grad) 
{
	Dificultate = Grad;
}

void Interfata::GetName()
{
	this->SetName();
}

void Interfata::GetDifficulty()
{
	int Grad;

	COORD p = { 30, 13 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);

	std::cout << "Introduceti nivelul de dificultate intre 1 si 3:";
	std::cin >> Grad;
	this->SetDifficulty(Grad);
	system("cls");
}

void Interfata::ChooseLayout()
{
	this->Draw_Table();
	switch(Dificultate)
	{
	case(1):

		this->Layout_LVL1();
		break;

	case(2):

		this->Layout_LVL2();
		break;

	case(3):
	
		this->Layout_LVL3();
		break;

	default:
		COORD p = { 50, 13 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		std::cout << "Nu este o optiune valida!";
		break;
	}
}

void Interfata::Draw_Table()
{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

	
	conOut(LinScore, 0) <<Username;
	conOut(LinScore + 1, 0) << "Score:0" ;                                    
	conOut(LinScore + 2, 0) << "Sun:50";
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j <= ColLenght; j++) 
		{
			if (i == 3 && j % 15 == 0)
			{
				conOut(i, j) << '+';
			}
			else {
				if (j % 15 == 0) 
				{
					conOut(i, j) << '|';
				}
				if (i == 3)
				{
					conOut(i, j) << '-';
				}
			}
			if (i == 0 && j <= 15) 
			{
				conOut(i, j) << "-";
			}
		}
	}
	conOut(3, 0) << "-";

	for (int i = 4; i < LinLenght - 6; i++) 
	{

		for (int j = 0; j <= 15; j++) 
		{


			if ((i + 3) % 6 == 0) 
			{
				conOut(i, j) << "-";
			}
			if (j == 15)
				conOut(i, j) << "|";

		}
	}

	conOut(6, 3) << "Sunflower";
	conOut(7, 6) << "50";
	conOut(12, 3) << "PeaShooter";
	conOut(13, 6) << "100";
	conOut(18, 4) << "Wallnut";
	conOut(19, 6) << "150";
}

Interfata::Interfata()
{
	
}

Interfata::~Interfata()
{

}