#include "Sun.h"
#include<iostream>
#include<random>
#include<time.h>
#include"ConsoleOutput.h"
#include<chrono>
#include<stdlib.h>
#include<fstream>
using namespace std::chrono;
using namespace std;
Sun::Sun()
{
	value = 100;
};
Sun::~Sun()
{

};
void Sun::setPosition(int x, int y)
{
	ofstream logfile;
	logfile.open("log.exe");
	logfile << "Initializare soare...\n";
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	random_device rd; 
	mt19937 eng(rd());
	int random;
	static auto end = steady_clock:: now();
	uniform_int_distribution<> distr(31, 37); 
	random=distr(eng);
	if (duration_cast<seconds>(steady_clock::now() - end).count() > 3)
	{
		end = steady_clock::now(); 
		switch (random)
		{
		case 31:
		{
			conOut(10, random) << "O";
			break;
		}



		case 33:
		{
			conOut(10, random) << "O";
			break;
		}

		case 35:
		{
			conOut(10, random) << "O";
			break;
		}
		case 37:
		{
			conOut(10, random) << "O";
			break;
		}
		}
	}
}
int Sun::getValue()
{
	return this->value;
}