#include "Game.h"
#include <conio.h>



void main()
{
	try
	{
		Game& game = Game::getInstance();
	}
	catch (...)
	{
		system("cls");
		std::cout << "esti prost                ";
	}
	_getch();
}

