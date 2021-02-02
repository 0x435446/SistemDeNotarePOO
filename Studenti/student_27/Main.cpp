//#include "ConsoleInput.h"
//#include "ConsoleOutput.h"
//#include <time.h>
//#include <chrono>
//#include<Windows.h>
//#include<iostream>
//#include"Player.h"
//#include<thread>
//#include"Sun.h"

#include"Game.h"
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>


#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5


#define IDB_BUT 1001

using namespace std::chrono;


//GenerateSun* GenerateSun::instance = nullptr;

int main(void)
{
	iGame* game = iGame::get_instance();

	game->Listen();

	_getch();

   return 0;
}

