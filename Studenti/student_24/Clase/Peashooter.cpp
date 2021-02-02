#pragma once
#include "Peashooter.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include <iostream>
#include "ConsoleInput.h"

using namespace std::chrono;

Peashooter::Peashooter(int a, int b)
{
	x = a+1;
	y = b+3;
	set(100, 20, 10);
}



void Peashooter::draw()
{

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x , y) << "(= O";
	conOut(x + 1, y) << " | ";
	conOut(x + 2, y) << "---";


}

void Peashooter::uppdate(std::string action)
{
	ability();
	for (auto i:shot)
	{
		i->uppdate(action);
		if (i->gety() >= 110||i->getlife()==0)
		{
			shot.erase(shot.begin());
			delete i;
		}
		
	}

	draw();
}

void Peashooter::ability()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	t.update();
	if(t.durata()>2)
	{
		
		shot.push_back(new Pea(x, y + 4));
		t.set_time();
		t.update();
	}
}

void Peashooter::set(int price, int resistance, int grow_time)
{
	this->price = price;
	this->resistance = resistance;
	this->grow_time = grow_time;
}

Peashooter::Peashooter()
{
	set(100, 20, 10);

}


Peashooter::~Peashooter()
{

}
