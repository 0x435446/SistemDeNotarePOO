#include "PeaProjectile.h"
#include<iostream>
#include"ConsoleInput.h"
#include"ConsoleOutput.h"
#include"Peashooter.h"
#include<chrono>
#include<thread>
#include"zombie.h"
#include<windows.h>
#include<memory>
#include<fstream>
using namespace std::chrono;
using namespace std;
PeaProjectile::PeaProjectile()
{
	dmg = 25;
};
PeaProjectile::~PeaProjectile()
{

}
int PeaProjectile::getX()
{
	return this->x;
}
int PeaProjectile::getY()
{
	return this->y;
}
void PeaProjectile::setPosition(int x, int y)
{
	ofstream logfile;
	logfile.open("log.exe");
	logfile << "Setare proiectil...\n";
	static int xzombie, yzombie,lovit;
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static std::string printedChar = "-";
	static int col;
	col = x;
	lovit = 0;
	while (col <= 69)
	{
				
				std::this_thread::sleep_for(std::chrono::milliseconds(20));
				conOut(y, col + 1) << printedChar;
				std::this_thread::sleep_for(std::chrono::milliseconds(30));
				conOut(y, col + 1) << " ";
				col++;
				this->x = col;
				if (col == 68)
					col = x;
	}
	
}
