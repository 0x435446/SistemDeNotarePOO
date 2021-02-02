#include "zombie.h"
#include<iostream>
#include"ConsoleInput.h"
#include"ConsoleOutput.h"
#include<chrono>
#include<random>
#include<stdlib.h>
#include<thread>
#include<fstream>
int castiga = 0;
using namespace std::chrono;
using namespace std;
zombie::zombie()
{
	health = 100;
	//this->x = updateX();
	//this->y = updateY();
}
void zombie::updateX(int x)
{
	this->x = x;
}
void zombie::updateY(int y)
{
	this->y = y;
}
zombie::zombie(int x, int y)
{
	this->health = 100;
	this->x = x;
	this->y = y;
}

zombie::~zombie()
{

}
int zombie::getX()
{
	return this->x;
}

int zombie::getY()
{
	return this->y;
}

void zombie::setPosition(int x, int y)
{
	ofstream logfile;
	logfile.open("log.exe");
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	random_device rd;
	mt19937 eng(rd());
	int random, col, row;
	static auto end = steady_clock::now();
	uniform_int_distribution<> distr(14, 20);
	string shape = "Z";
	random = distr(eng);
	col = random;
	row = 69;
	logfile<<"Initializare zombie...\n";
	if (duration_cast<seconds>(steady_clock::now() - end).count() > 5)
	{
		end = steady_clock::now();
		switch (random)
		{
		case 14:
		{
			int count = 0;
			while (row >= 28)
			{
				if (count == 20)
				{
					castiga++;
					if (castiga == 4)
					{
						conOut(50, 50) << "GAME WON";
						exit(0);

					}
					return;
				}
				conOut(col, row - 1) << shape;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				conOut(col, row-1) << " ";
				row--;
				if (row == 28)
				{
					col = x;
					for (int i = 0; i < 40; i++)
						for (int j = 0; j < 173; j++)
							conOut(i, j) << " ";
					conOut(70, 17) << "It's OVAH'";
					exit(0);
				}
				this->x=row;
				this->y = col;
				count++;
			}
			break;
		}



		case 16:
		{
			int count = 0;
			while (row >= 28)
			{
				if (count == 15)
				{
					castiga++;
					if (castiga == 4)
					{
						conOut(50, 50) << "GAME WON";
						exit(0);

					}
					return;
				}
				conOut(col, row-1) << "Z";
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				conOut(col, row-1) << " ";
				row--;
				if (row == 28)
				{
					col = x;
					for (int i = 0; i < 40; i++)
						for (int j = 0; j < 173; j++)
							conOut(i, j) << " ";
					conOut(70, 17) << "It's OVAH'";
					exit(0);
				}
				this->x = row;
				this->y = col;
				count++;
			}
			break;
		}

		case 18:
		{	
			int count = 0;
			while (row >= 28)
			{
				if (count == 18)
				{
					castiga++;
					if (castiga == 4)
					{
						conOut(50, 50) << "GAME WON";
						exit(0);

					}
					return;
				}
				conOut(col, row - 1) << "Z";
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				conOut(col, row - 1) << " ";
				row--;
				if (row == 28)
				{
					col = x;
					for (int i = 0; i < 40; i++)
						for (int j = 0; j < 173; j++)
							conOut(i, j) << " ";
					conOut(70, 17) << "It's OVAH'";
					exit(0);
				}
				this->x = row;
				this->y = col;
				count++;
			}
			break;
		}
		case 20:
		{
			int count = 0;
			while (row >= 28)
			{
				if (count == 21)
				{
					return;
					castiga++;
					if (castiga == 4)
					{
						conOut(50, 50) << "GAME WON";
						exit(0);

					}
				}
				conOut(col, row - 1) << "Z";
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				conOut(col, row - 1) << " ";
				row--;
				if (row == 28)
				{
					col = x;
					for (int i = 0; i < 40; i++)
						for (int j = 0; j < 173; j++)
							conOut(i, j) << " ";
					conOut(70, 17) << "It's OVAH'";
					exit(0);
				}
				this->x = row;
				this->y = col;
				count++;
			}
			break;
		}
		}
	}
	
}



