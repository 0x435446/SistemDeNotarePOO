#include <iostream>
#include <windows.h>

#include "Utilizator.h"

void Utilizator::SetName()
{
	COORD p = { 50, 13 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	std::cout << "Introduceti numele utilizatorului:\n";
	p = { 60, 15 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	std::cin >> Username;
	system("cls");
}

Utilizator::Utilizator()
{

}

Utilizator::~Utilizator()
{

}