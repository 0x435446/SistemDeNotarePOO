#include "Map.h"
#pragma once
std::vector<Zombie*> Map::zombie;

using namespace std::chrono;



void Map::set(int a, int b)
{
	x = a; y = b;
}

void Map::create_zombie(std::string action)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	t.update();
	auto id = rand() % 5;
	auto id2 = rand() % 15 + 15;

	if (t.durata()> id2)
	{
	
		zombie.push_back(new Zombie(id * 4 + 17, 110));
		for (auto i : zombie)
			i->uppdate(action);
		t.set_time();
		t.update();
	}


}

void Map::plantare(std::string action)
{
	
	Shop *s = Shop::getinstance();
	for(auto i:teren)
		if (i->selected(action)==true && s->gettype() != 0 && i->isfilled()==0)
		{
		
			if (s->gettype() == 1)
			{
				i->plant_Peashooter();
				s->settype(0);
				i->setfilled();

			}
			else if (s->gettype() == 2)
			{
				i->plant_Sunflower();
				s->settype(0);
				i->setfilled();
			}
		}

	


}

Map::Map()
{
	set(16, 30);
	for(int j=0;j<5;j++)
		for (int i = 0; i < 9; i++)
			teren.push_back(new Parcela(x+j*4, y+i*9));


}




Map::~Map()
{
}

void Map::draw()
{
	for (auto it : teren)
		it->draw();

}

void Map::uppdate(std::string action)
{
	int aux = 0;
	plantare(action);
	for (auto i : teren)
		i->uppdate(action);
	create_zombie(action);
	for (auto i : zombie)
	{
		aux++;
		if (i->getlife() == 0)
		{
			zombie.erase(zombie.begin() + aux - 1);
			delete i;
			aux--;
		}
		else
		    i->uppdate(action);
	
	}


}
