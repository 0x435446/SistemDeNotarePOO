#define _CRT_SECURE_NO_WARNINGS

#include "Sun.h"
#include "ConsoleOutput.h"
#include "ConsoleInput.h"

#include <chrono>
#include <time.h>
#include <Windows.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <random>

#define SUN_APPEAR_Y_START 9
#define SUN_APPEAR_X_START 23
#define SUN_SCORE 10


using namespace std::chrono;
Sun::Sun()
{
}
Sun::~Sun()
{
}

Sun & Sun::getInstance(void)
{
	if (Sun::instance==nullptr)
	{
		Sun::instance = new Sun();
	}
	return *instance;
}

void Sun::buy_sunflower()
{
	if (this->sun_appear_time!=1)
	{
		this->sun_appear_time = this->sun_appear_time - (float)0.5;
		
	}

}

void Sun::print_score()
{
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 3; i++)
	{
		conOut(11, 13 + i) << " ";
	}
	conOut(11, 13) << this->score;
}

void Sun::generate()
{
	
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

	
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	int i;
	if (duration_cast<seconds>(end - begin).count() > this->sun_appear_time)
	{
		begin = end;
		srand((int)time(0));
		
		i = (rand() % 10) + 1;

		if ((i == 1) && (this->v[i] == 0))
		{
			conOut(SUN_APPEAR_Y_START, SUN_APPEAR_X_START +1) << "____";
			conOut(SUN_APPEAR_Y_START + 1, SUN_APPEAR_X_START ) << "/\\  /\\";
			conOut(SUN_APPEAR_Y_START + 2, SUN_APPEAR_X_START  ) << "|-()-|";
			conOut(SUN_APPEAR_Y_START + 3, SUN_APPEAR_X_START ) << "\\/__\\/";
			this->v[i] = 1;
		}
		else if ((i == 2) && (this->v[i] == 0))
		{
			conOut(SUN_APPEAR_Y_START, SUN_APPEAR_X_START + 1 +9*1) << "____";
			conOut(SUN_APPEAR_Y_START + 1, SUN_APPEAR_X_START +9*1) << "/\\  /\\";
			conOut(SUN_APPEAR_Y_START + 2, SUN_APPEAR_X_START  +9*1) << "|-()-|";
			conOut(SUN_APPEAR_Y_START + 3, SUN_APPEAR_X_START +9*1) << "\\/__\\/";
			v[i] = 1;
		}
		else if ((i == 3) && (this->v[i] == 0))
		{
			conOut(SUN_APPEAR_Y_START, SUN_APPEAR_X_START + 1 + 9 * 2) << "____";
			conOut(SUN_APPEAR_Y_START + 1, SUN_APPEAR_X_START + 9 * 2) << "/\\  /\\";
			conOut(SUN_APPEAR_Y_START + 2, SUN_APPEAR_X_START  + 9 * 2) << "|-()-|";
			conOut(SUN_APPEAR_Y_START + 3, SUN_APPEAR_X_START + 9 * 2) << "\\/__\\/";
			this->v[i] = 1;
		}
		else if ((i == 4) && (this->v[i] == 0))
		{
			conOut(SUN_APPEAR_Y_START, SUN_APPEAR_X_START + 1 + 9 * 3) << "____";
			conOut(SUN_APPEAR_Y_START + 1, SUN_APPEAR_X_START + 9 * 3) << "/\\  /\\";
			conOut(SUN_APPEAR_Y_START + 2, SUN_APPEAR_X_START  + 9 * 3) << "|-()-|";
			conOut(SUN_APPEAR_Y_START + 3, SUN_APPEAR_X_START + 9 * 3) << "\\/__\\/";
			this->v[i] = 1;
		}
		else if ((i == 5) && (this->v[i] == 0))
		{
			conOut(SUN_APPEAR_Y_START, SUN_APPEAR_X_START + 1 + 9 * 4) << "____";
			conOut(SUN_APPEAR_Y_START + 1, SUN_APPEAR_X_START + 9 * 4) << "/\\  /\\";
			conOut(SUN_APPEAR_Y_START + 2, SUN_APPEAR_X_START  + 9 * 4) << "|-()-|";
			conOut(SUN_APPEAR_Y_START + 3, SUN_APPEAR_X_START + 9 * 4) << "\\/__\\/";
			this->v[i] = 1;
		}
		else if ((i == 6) && (this->v[i] == 0))
		{
			conOut(SUN_APPEAR_Y_START, SUN_APPEAR_X_START + 1 + 9 * 5) << "____";
			conOut(SUN_APPEAR_Y_START + 1, SUN_APPEAR_X_START + 9 * 5) << "/\\  /\\";
			conOut(SUN_APPEAR_Y_START + 2, SUN_APPEAR_X_START + 9 * 5) << "|-()-|";
			conOut(SUN_APPEAR_Y_START + 3, SUN_APPEAR_X_START + 9 * 5) << "\\/__\\/";
			this->v[i] = 1;
		}
		else if ((i == 7) && (this->v[i] == 0))
		{
			conOut(SUN_APPEAR_Y_START, SUN_APPEAR_X_START + 1 + 9 * 6) << "____";
			conOut(SUN_APPEAR_Y_START + 1, SUN_APPEAR_X_START + 9 * 6) << "/\\  /\\";
			conOut(SUN_APPEAR_Y_START + 2, SUN_APPEAR_X_START + (9 * 6)) << "|-()-|";
			conOut(SUN_APPEAR_Y_START + 3, SUN_APPEAR_X_START + 9 * 6) << "\\/__\\/";
			this->v[i] = 1;
		}
		else if ((i == 8) && (this->v[i] == 0))
		{
			conOut(SUN_APPEAR_Y_START, SUN_APPEAR_X_START + 1 + 9 * 7) << "____";
			conOut(SUN_APPEAR_Y_START + 1, SUN_APPEAR_X_START + 9 * 7) << "/\\  /\\";
			conOut(SUN_APPEAR_Y_START + 2, SUN_APPEAR_X_START + (9 * 7)) << "|-()-|";
			conOut(SUN_APPEAR_Y_START + 3, SUN_APPEAR_X_START + 9 * 7) << "\\/__\\/";
			this->v[i] = 1;
		}
		else if ((i == 9) && (this->v[i] == 0))
		{
			conOut(SUN_APPEAR_Y_START, SUN_APPEAR_X_START + 1 + 9 * 8) << "____";
			conOut(SUN_APPEAR_Y_START + 1, SUN_APPEAR_X_START + 9 * 8) << "/\\  /\\";
			conOut(SUN_APPEAR_Y_START + 2, SUN_APPEAR_X_START + (9 * 8) ) << "|-()-|";
			conOut(SUN_APPEAR_Y_START + 3, SUN_APPEAR_X_START + 9 * 8) << "\\/__\\/";
			this->v[i] = 1;
		}
	}
}
void Sun::collect(std::string action)
{
	char *p;
	int x = 0;
	int y = 0;
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	

	char cpy[100];
	strcpy(cpy, action.c_str());
	p = strtok(cpy, " ");
	while (p)
	{
		if (strcmp(p, "double") == 0)
		{

			for (int j = 1; j <= 3; j++)
			{
				p = strtok(NULL, " (");
			}
			x = atoi(p);
			p = strtok(NULL, ", ");
			y = atoi(p);

			if (    ((y == SUN_APPEAR_Y_START +1)||(y== SUN_APPEAR_Y_START +2)||(y== SUN_APPEAR_Y_START+3)   )&&(    (x <=SUN_APPEAR_X_START + (9*1) -3) && (x>=SUN_APPEAR_X_START -1 +(9*0) ))   )
			{
				if (v[1] == 1)
				{
					for (int y = SUN_APPEAR_Y_START ; y <= 12; y++)
					{
						for (int x = ( SUN_APPEAR_X_START - 1 + (9 * 0)); x <= SUN_APPEAR_X_START + (9 * 1) - 3 ; x++)
						{
							conOut(y, x) << ' ';
						}
					}
					v[1] = 0;
					this->score = this->score + SUN_SCORE;

				}
			}
			if (((y == SUN_APPEAR_Y_START + 1) || (y == SUN_APPEAR_Y_START + 2) || (y == SUN_APPEAR_Y_START + 3)) &&( (x <= SUN_APPEAR_X_START + (9 * 2) - 3) && (x >= SUN_APPEAR_X_START - 1 + (9 * 1))))
			{
				if (v[2] == 1)
				{
					for (int y = SUN_APPEAR_Y_START; y <= 12; y++)
					{
						for (int x = (SUN_APPEAR_X_START - 1 + (9 * 1)); x <= SUN_APPEAR_X_START + (9 * 2) - 3; x++)
						{
							conOut(y, x) << ' ';
						}
					}
					v[2] = 0;
					this->score = this->score + SUN_SCORE;

				}
			}
			if (((y == SUN_APPEAR_Y_START + 1) || (y == SUN_APPEAR_Y_START + 2) || (y == SUN_APPEAR_Y_START + 3)) &&( (x <= SUN_APPEAR_X_START + (9 * 3) - 3) && (x >= SUN_APPEAR_X_START - 1 + (9 * 2))))
			{
				if (v[3] == 1)
				{
					for (int y = SUN_APPEAR_Y_START; y <= 12; y++)
					{
						for (int x = (SUN_APPEAR_X_START - 1 + (9 * 2)); x <= SUN_APPEAR_X_START + (9 * 3) - 3; x++)
						{
							conOut(y, x) << ' ';
						}
					}
					v[3] = 0;
					this->score = this->score + SUN_SCORE;

				}
			}
			if (((y == SUN_APPEAR_Y_START + 1) || (y == SUN_APPEAR_Y_START + 2) || (y == SUN_APPEAR_Y_START + 3)) &&( (x <= SUN_APPEAR_X_START + (9 * 4) - 3) && (x >= SUN_APPEAR_X_START - 1 + (9 *3))))
			{
				if (v[4] == 1)
				{
					for (int y = SUN_APPEAR_Y_START; y <= 12; y++)
					{
						for (int x = (SUN_APPEAR_X_START - 1 + (9 * 3)); x <= SUN_APPEAR_X_START + (9 * 4) - 3; x++)
						{
							conOut(y, x) << ' ';
						}
					}
					v[4] = 0;
					this->score = this->score + SUN_SCORE;

				}
			}
			if (((y == SUN_APPEAR_Y_START + 1) || (y == SUN_APPEAR_Y_START + 2) || (y == SUN_APPEAR_Y_START + 3)) &&( (x <= SUN_APPEAR_X_START + (9 *5) - 3) && (x >= SUN_APPEAR_X_START - 1 + (9 *4))))
			{
				if (v[5] == 1)
				{
					for (int y = SUN_APPEAR_Y_START; y <= 12; y++)
					{
						for (int x = (SUN_APPEAR_X_START - 1 + (9 * 4)); x <= SUN_APPEAR_X_START + (9 * 5) - 3; x++)
						{
							conOut(y, x) << ' ';
						}
					}
					v[5] = 0;
					this->score = this->score + SUN_SCORE;

				}
			}
			if (((y == SUN_APPEAR_Y_START + 1) || (y == SUN_APPEAR_Y_START + 2) || (y == SUN_APPEAR_Y_START + 3)) &&( (x <= SUN_APPEAR_X_START + (9 * 6) - 3) && (x >= SUN_APPEAR_X_START - 1 + (9 * 5))))
			{
				if (v[6] == 1)
				{
					for (int y = SUN_APPEAR_Y_START; y <= 12; y++)
					{
						for (int x = (SUN_APPEAR_X_START - 1 + (9 * 5)); x <= SUN_APPEAR_X_START + (9 * 6) - 3; x++)
						{
							conOut(y, x) << ' ';
						}
					}
					v[6] = 0;
					this->score = this->score + SUN_SCORE;

				}
			}
			if (((y == SUN_APPEAR_Y_START + 1) || (y == SUN_APPEAR_Y_START + 2) || (y == SUN_APPEAR_Y_START + 3)) &&( (x <= SUN_APPEAR_X_START + (9 * 7) - 3) && (x >= SUN_APPEAR_X_START - 1 + (9 * 6))))
			{
				if (v[7] == 1)
				{
					for (int y = SUN_APPEAR_Y_START; y <= 12; y++)
					{
						for (int x = (SUN_APPEAR_X_START - 1 + (9 * 6)); x <= SUN_APPEAR_X_START + (9 * 7) - 3; x++)
						{
							conOut(y, x) << ' ';
						}
					}
					v[7] = 0;
					this->score = this->score + SUN_SCORE;

				}
			}
			if (((y == SUN_APPEAR_Y_START + 1) || (y == SUN_APPEAR_Y_START + 2) || (y == SUN_APPEAR_Y_START + 3)) &&( (x <= SUN_APPEAR_X_START + (9 * 8) - 3) && (x >= SUN_APPEAR_X_START - 1 + (9 * 7))))
			{
				if (v[8] == 1)
				{
					for (int y = SUN_APPEAR_Y_START; y <= 12; y++)
					{
						for (int x = (SUN_APPEAR_X_START - 1 + (9 * 7)); x <= SUN_APPEAR_X_START + (9 * 8) - 3; x++)
						{
							conOut(y, x) << ' ';
						}
					}
					v[8] = 0;
					this->score = this->score + SUN_SCORE;

				}
			}
			if (((y == SUN_APPEAR_Y_START + 1) || (y == SUN_APPEAR_Y_START + 2) || (y == SUN_APPEAR_Y_START + 3)) && ((x <= SUN_APPEAR_X_START + (9 * 9) - 3) && (x >= SUN_APPEAR_X_START - 1 + (9 * 8))))
			{
				if (v[9] == 1)
				{
					for (int y = SUN_APPEAR_Y_START; y <= 12; y++)
					{
						for (int x = (SUN_APPEAR_X_START - 1 + (9 * 8)); x <= SUN_APPEAR_X_START + (9 * 9) - 3; x++)
						{
							conOut(y, x) << ' ';
						}
					}
					v[9] = 0;
					this->score = this->score + SUN_SCORE;
					
				}
			}





		}
		p = strtok(NULL, ") ");
	}


}

WORD Sun::GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}

Sun * Sun::instance = nullptr;

