#pragma once
#include "Zombie.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
using namespace std::chrono;


int Zombie::getx()
{
	return x;
}

int Zombie::gety()
{
	return y;
}

int Zombie::getlife()
{
	return life;
}

void Zombie::lifeminus(int x)
{
	life=life - x;
}

Zombie::Zombie(int a,int b)
{
	life = 7;
	x = a;
	y = b+3;
	draw();
	y--;
}




void Zombie::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << "(QQ)";
	conOut(x + 1, y) << ">|>]";
	conOut(x + 2, y) << " / |";



}

void Zombie::uppdate(std::string)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	t.update();
	if (t.durata() > 0.5f)
	{
		conOut(x, y + 1) << "     ";
		conOut(x + 1, y + 1) << "     ";
		conOut(x + 2, y + 1) << "     ";
		draw();
		y--;
		t.set_time();
		t.update();
	}
}


Zombie::~Zombie()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << "     ";
	conOut(x + 1, y) << "     ";
	conOut(x + 2, y) << "     ";

}
