#include "Plant.h"
#include<chrono>
#include "ConsoleOutput.h"
#include <time.h>
#include <time.h>
#include <chrono>
#include "Scor.h"
#include "Peashooter.h"
#include "Sunflower.h"
using namespace std::chrono;

Plant::Plant()
{
}

Plant::Plant(int x, int y)
{
	this->x = x;
	this->y = y;
	for (int i = 0; i < 5; i++)
	{
		vect.push_back(new Zona(x+i*6, y ));
	}
}

Plant::~Plant()
{
}

void Plant::set_position(int a, int b)
{
	x = a;
	y = b;
}

void Plant::draw()
{
	for (auto it : vect)
		it->draw_zona_plante();
}

void Plant::update(std::string action)
{
	
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	Scor *scor = Scor::getInstance();

	Peashooter plant1(vect[0]->get_x() + 2, vect[0]->get_y() + 2);
	vect[0]->set_filed();
	plant1.draw();
	Sunflower plant2(vect[4]->get_x() + 2, vect[4]->get_y() + 2);
	vect[1]->set_filed();
	plant2.draw();
}