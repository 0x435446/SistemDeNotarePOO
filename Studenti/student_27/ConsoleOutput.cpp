#include "ConsoleOutput.h"
#include <windows.h>
#include <time.h>
#include <chrono>
#include<Windows.h>
using namespace UserInterface;

using namespace std::chrono;

void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
			if (printedChar == "*")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "*";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_STARS;
		}
	}
}

ConsoleOutput::ConsoleOutput()
{
	// setting console width and height
	HWND console = GetConsoleWindow();
	MoveWindow(console, 0, 0, CON_WIDTH, CON_HEIGHT, TRUE);

	// hiding scrollbar
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);

	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);

	// hide blinking cursor
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(handle, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(handle, &cursorInfo);
}

ConsoleOutput::~ConsoleOutput()
{
}

ConsoleOutput & ConsoleOutput::getInstance()
{
	ConsoleOutput *console = new ConsoleOutput();
	return *console;
}

ConsoleOutput & UserInterface::ConsoleOutput::operator()(int row, int col)
{
	/*should check wether the row and the column values ar within the limits of the current window*/
	COORD coord;
	coord.X = col;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return *this;
}

void UserInterface::ConsoleOutput::Create_Start()
{

	this->Create_Score(FIRST_ROW, FIRST_COL);

	this->Create_Plant_Zone(FIRST_ROW, FIRST_COL);

	this->Create_Plant_Zone(FIRST_ROW+7, FIRST_COL);

	this->Create_Plant_Zone(FIRST_ROW + 14, FIRST_COL);

	this->Create_Plant_Zone(FIRST_ROW + 21, FIRST_COL);

	this->Create_Plant_Zone(FIRST_ROW + 28, FIRST_COL);

	this->Create_Border1(FIRST_ROW, FIRST_COL);

	this->Create_Sun_Zone(FIRST_ROW, FIRST_COL);

	this->Create_Sun_Zone(FIRST_ROW, FIRST_COL+15);

	this->Create_Sun_Zone(FIRST_ROW, FIRST_COL + 30);

	this->Create_Sun_Zone(FIRST_ROW, FIRST_COL + 45);

	this->Create_Sun_Zone(FIRST_ROW, FIRST_COL + 60);

	this->Create_Sun_Zone(FIRST_ROW, FIRST_COL + 75);

	this->Create_Sun_Zone(FIRST_ROW, FIRST_COL + 90);

	this->Create_Sun_Zone(FIRST_ROW, FIRST_COL + 105);

	this->Create_Sun_Zone(FIRST_ROW, FIRST_COL + 120);

	this->Create_Battle_Field(FIRST_ROW, FIRST_COL);

	this->Create_Battle_Zone(FIRST_ROW, FIRST_COL);

}

void UserInterface::ConsoleOutput::Create_Plant_Zone(int row, int col)
{
	UserInterface::ConsoleOutput conOuT = UserInterface::ConsoleOutput::getInstance();



	/*conOuT(row, col) << "/";
	conOuT(row + 1, col - 1) << "/";
	conOuT(row + 2, col - 2) << "/";

	conOuT(row, col + 1) << "\\";
	conOuT(row + 1, col + 2) << "\\";
	conOuT(row + 2, col + 3) << "\\";

	conOuT(row + 3, col - 2) << "\\";
	conOuT(row + 4, col - 1) << "\\";
	conOuT(row + 5, FIRST_COL) << "\\";

	conOuT(row + 3, col + 3) << "/";
	conOuT(row + 4, col + 2) << "/";
	conOuT(row + 5, col + 1) << "/";*/

	char left_up = 201;

	char left_down = 200;

	char right_up = 187;

	char right_down = 188;

	char down_up = 186;

	char left_right = 205;


	conOuT(row + 3, col-3) << left_up; 
	conOuT(row + 4, col-3) << down_up;
	conOuT(row + 5, col-3) << left_down;
	conOuT(row + 5, col-2) << left_right;
	conOuT(row + 5, col - 1) << left_right;
	conOuT(row + 5, col) << left_right;
	conOuT(row + 5, col+1) << right_down;
	conOuT(row + 4, col+1) << down_up;
	conOuT(row + 3, col+1) << right_up;
	conOuT(row + 3, col) << left_right;
	conOuT(row + 3, col-1) << left_right;
	conOuT(row + 3, col-2) << left_right;




}

void UserInterface::ConsoleOutput::Create_Score(int row, int col)
{
	UserInterface::ConsoleOutput conOuT = UserInterface::ConsoleOutput::getInstance();

	char i = 201;

	char j = 186;

	char k = 200;

	char z = 205;

	char x = 188;

	char t = 187;

	conOuT(row-4, col-4) <<i;
	conOuT(row-3, col-4) << j;
	conOuT(row-2, col-4) << j;
	conOuT(row-1, col-4) << k;

	conOuT(row - 1, col-3) << z;
	conOuT(row - 1, col-2) << z;
	conOuT(row - 1, col-1) << z;
	conOuT(row - 1, col) << z;
	conOuT(row - 1, col+1) << z;
	conOuT(row - 1, col+2) << z;
	conOuT(row - 1, col+3) << z;
	
	conOuT(row - 1, col+4) << x;
	conOuT(row -2, col + 4) << j;
	conOuT(row - 3, col + 4) << j;
	conOuT(row - 4, col + 4) << t;

	conOuT(row - 4, col + 3) << z;
	conOuT(row - 4, col + 2) << z;
	conOuT(row - 4, col + 1) << z;
	conOuT(row - 4, col) << z;
	conOuT(row - 4, col -1) << z;
	conOuT(row - 4, col - 2) << z;
	conOuT(row - 4, col - 3) << z;

	conOuT(row - 3, col - 1) << "Sun";

	conOuT(row - 2, col) << "0";
}

void UserInterface::ConsoleOutput::Create_Border1(int row, int col)
{
	UserInterface::ConsoleOutput conOuT = UserInterface::ConsoleOutput::getInstance();

	char i = 201;

	char j = 186;

	char k = 200;

	char z = 205;

	char x = 188;

	char t = 187;

	conOuT(row - 4, col +5) << i;
	conOuT(row - 3, col +5) << j;
	conOuT(row - 2, col +5) << j;
	conOuT(row - 1, col + 5) << j;
	conOuT(row , col +5) << k;


	for(int count=6;count<=141;count++)
	conOuT(row, col + count) << z;

	conOuT(row, col +142) << x;
	conOuT(row -1, col +142) << j;
	conOuT(row -2, col +142) << j;
	conOuT(row -3, col +142) << j;

	conOuT(row -4, col + 142) << t;

	for(int count=141;count>=6 ;count--)
		conOuT(row-4, col + count) << z;
	

}

void UserInterface::ConsoleOutput::Create_Sun_Zone(int row, int col)
{

	UserInterface::ConsoleOutput conOuT = UserInterface::ConsoleOutput::getInstance();

	char left_up = 218;

	char down = 179;

	char left_down = 192;

	char right = 196;

	char right_down = 217;

	char right_up = 191;

	conOuT(row - 3, col + 8) << left_up;

	conOuT(row - 2, col + 8) << down;

	conOuT(row - 1, col + 8) << left_down;

	for(int i=9;i<=15;i++)
		conOuT(row - 1, col + i) << right;

	conOuT(row - 1, col + 16) << right_down;

	conOuT(row - 2, col + 16) << down;

	conOuT(row - 3, col + 16) << right_up;

	for (int i = 9; i <= 15; i++)
		conOuT(row - 3, col + i) << right;

}

void UserInterface::ConsoleOutput::Create_Battle_Field(int row, int col)
{
	UserInterface::ConsoleOutput conOuT = UserInterface::ConsoleOutput::getInstance();

	char left_up = 201;

	char left_down = 200;

	char right_up = 187;

	char right_down = 188;

	char down_up = 186;

	char left_right = 205;

	conOuT(row+2, col+5) << left_up;

	for (int i = 8; i <= 36; i++)
		conOuT(i, col + 5) << down_up;

	conOuT(37, col + 5) << left_down;

	for(int i=11;i<=146;i++)
		conOuT(37, i) << left_right;

	conOuT(37, 147) << right_down;

	for (int i = 8; i <= 36; i++)
		conOuT(i, 147) << down_up;

	conOuT(7, 147) << right_up;

	for (int i = 11; i <= 146; i++)
		conOuT(7, i) << left_right;




}

void UserInterface::ConsoleOutput::Create_Battle_Zone(int row, int col)
{

	UserInterface::ConsoleOutput conOuT = UserInterface::ConsoleOutput::getInstance();

	char left_up = 218;

	char down = 179;

	char left_down = 192;

	char right = 196;

	char right_down = 217;

	char right_up = 191;

	for (int i = 12; i <= 37; i = i + 6)

	{
		this->Create_Sun_Zone(i, 5);

		this->Create_Sun_Zone(i, 20);

		this->Create_Sun_Zone(i, 35);

		this->Create_Sun_Zone(i, 50);

		this->Create_Sun_Zone(i, 65);

		this->Create_Sun_Zone(i, 80);

		this->Create_Sun_Zone(i, 95);

		this->Create_Sun_Zone(i, 110);

		this->Create_Sun_Zone(i, 125);
	}



}

void UserInterface::ConsoleOutput::Game_Loading()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	std::string Msg = "Loading cool game now...";

	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << Msg;

	int x = 5;

	int y = 0;

	while (x > 0)
	{
		doLoadingBar();
		Sleep(150);
		y++;
		if (y == 5)
		{
			x = x - 1;
			y = 0;
		}

		if (x == 0)
		{
			int j = COL_FIRST_STAR_POSITION + Msg.length() - 1;
			for (int i = COL_FIRST_STAR_POSITION; i <= j; i++)
				conOut(ROW_TITLE, i) << " ";

			int i = COL_FIRST_STAR_POSITION;

			int number_of_start = 5;

			while (number_of_start > 0)

			{
				conOut(ROW_TITLE + 1, i) << " ";

				i = i + 5;

				number_of_start--;
			}
		}
	}
}
