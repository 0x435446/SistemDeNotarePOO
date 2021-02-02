#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include <Windows.h>
#include <string>




#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		65
#define COL_DISTANCE_BETWEEN_STARS	5
#define BOARD_PLANTS_TABLE_Y 15
#define BOARD_PLANTS_TABLE_X 24

class Afisare
{
private:
	static Afisare *instance;
public:
		

		static Afisare & getInstance(void);
		void doLoadingBar();
		void printTitle();

		int check_board(int x_end, int  y_end, int level, int tip_planta);

		
		
		void Board_sun();
		void Board_plants();
		void Board_level_one();
		
		void print_lose();
		//void print_win();

		void print_pea(int i,int j){
			static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			conOut(BOARD_PLANTS_TABLE_Y + 2 + 5*j ,BOARD_PLANTS_TABLE_X + 1 + 12*i) << "O.O ";
			conOut(BOARD_PLANTS_TABLE_Y + 3 + 5*j,BOARD_PLANTS_TABLE_X + 2 + 12*i) << "O";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			conOut(BOARD_PLANTS_TABLE_Y + 4 + 5*j,BOARD_PLANTS_TABLE_X + 2 + 12*i) << "|";
		}
		void print_sunflower(int i,int j){
			static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
			conOut(BOARD_PLANTS_TABLE_Y + 2 + 5*j, BOARD_PLANTS_TABLE_X+12*i) << "/\\ /\\";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			conOut(BOARD_PLANTS_TABLE_Y + 3 + 5*j, BOARD_PLANTS_TABLE_X + 12 * i) << "_-O-_";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
			conOut(BOARD_PLANTS_TABLE_Y + 4 + 5*j, BOARD_PLANTS_TABLE_X + 12 * i) << "\\/ \\/";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			conOut(BOARD_PLANTS_TABLE_Y + 4 + 5 * j, BOARD_PLANTS_TABLE_X +2 + 12 * i) << "|";

		}
		void print_cherrybomb(int i, int j){
			static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			conOut(BOARD_PLANTS_TABLE_Y + 5*j + 3, BOARD_PLANTS_TABLE_X +1 + 12 * i) << "\\o/";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			conOut(BOARD_PLANTS_TABLE_Y + 5*j + 4, BOARD_PLANTS_TABLE_X + 1 + 12 * i) << "_I_";
		}
		void print_wallnut(int i, int j){
			static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			conOut(BOARD_PLANTS_TABLE_Y + 5*j + 1, BOARD_PLANTS_TABLE_X + 2 + 12 * i) << "_";
			conOut(BOARD_PLANTS_TABLE_Y + 5 * j + 2, BOARD_PLANTS_TABLE_X + 1 + 12 * i) << "/ \\";
			conOut(BOARD_PLANTS_TABLE_Y + 5*j + 3, BOARD_PLANTS_TABLE_X + 12 * i) << "/^ ^\\";
			conOut(BOARD_PLANTS_TABLE_Y + 5*j + 4, BOARD_PLANTS_TABLE_X + 12 * i) << "\\_-_/";
		}
		void print_snowpea(int i, int j){
			static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			conOut(BOARD_PLANTS_TABLE_Y + 5*j + 2, BOARD_PLANTS_TABLE_X +1+ 12 * i) << "__";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			conOut(BOARD_PLANTS_TABLE_Y + 5*j + 3, BOARD_PLANTS_TABLE_X + 12 * i) << "|";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			conOut(BOARD_PLANTS_TABLE_Y + 5*j + 3, BOARD_PLANTS_TABLE_X + 1 + 12 * i) << "o";
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
			conOut(BOARD_PLANTS_TABLE_Y + 5*j + 3, BOARD_PLANTS_TABLE_X + 2 + 12 * i) << "~**";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			conOut(BOARD_PLANTS_TABLE_Y + 5*j + 4, BOARD_PLANTS_TABLE_X + 1 + 12 * i) << "|";
		}
		void print_Pea_projectile(int i, int j)
		{

			static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			conOut(BOARD_PLANTS_TABLE_Y + 2 + 5 * j, BOARD_PLANTS_TABLE_X - 1 + 12 * i) << "o o o";
			conOut(BOARD_PLANTS_TABLE_Y + 2 + 5 * j, BOARD_PLANTS_TABLE_X + 6 + 12 * i) << "o o";

		}

		void print_Zombie(int i,int j){
			static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			conOut(BOARD_PLANTS_TABLE_Y + 5 * j + 1, BOARD_PLANTS_TABLE_X + 2 + 12 * i) << "__#";
			conOut(BOARD_PLANTS_TABLE_Y + 5 * j + 2, BOARD_PLANTS_TABLE_X + 3 + 12 * i) << "_|";
			conOut(BOARD_PLANTS_TABLE_Y + 5 * j + 3, BOARD_PLANTS_TABLE_X + 4 + 12 * i) << "|";
			conOut(BOARD_PLANTS_TABLE_Y + 5 * j + 4, BOARD_PLANTS_TABLE_X + 3 + 12 * i) << "| |";
		}
		void print_Bucket(int i, int j){
			static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			conOut(BOARD_PLANTS_TABLE_Y + 5 * j + 1, BOARD_PLANTS_TABLE_X + 1 + 12 * i) << "__[]";
			conOut(BOARD_PLANTS_TABLE_Y + 5 * j + 2, BOARD_PLANTS_TABLE_X + 3 + 12 * i) << "_|";
			conOut(BOARD_PLANTS_TABLE_Y + 5 * j + 3, BOARD_PLANTS_TABLE_X + 4 + 12 * i) << "|";
			conOut(BOARD_PLANTS_TABLE_Y + 5 * j + 4, BOARD_PLANTS_TABLE_X + 3 + 12 * i) << "| |";
		}
		void delete_zombie(int i, int j) {

			static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
			for (int x = 22; x <= 32; x++)
			{
				for (int y = 16; y <20 ; y++)
				{
					conOut(y + 5 * j, x + 12 * i) << " ";
				}
			}
		}
		WORD GetConsoleTextAttribute(HANDLE hCon);
	private:
			Afisare();
			~Afisare();
};



