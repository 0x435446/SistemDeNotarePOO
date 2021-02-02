#include "Resources.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include "Sun.h"
#include "ConsoleInput.h"
#include "Score.h"
using namespace std::chrono;

Score *scor = Score::getinstance();
Resources*Resources::instance = nullptr;

Resources * Resources::getinstance()
{
	if (instance == nullptr)
		instance = new Resources;
	return instance;
}

void Resources::set(int a, int b)
{
	x = a;
	y = b;
}

void Resources::lowfrecv(int x)
{
	frecv = frecv - x;
}

bool Resources::isfull()
{
	for (auto i : zone)
		if (i->isfilled() == false)
			return true;
	return false;
}


void Resources::uppdate(std::string action )
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	auto id = rand() % 9;
	auto end = steady_clock::now();
	if (isfull() == true)
	{
		while (zone[id]->isfilled() == true && isfull() == true)
		{
			id = rand() % 9;
		}
		if (duration_cast<seconds>(end - begin).count() > frecv)
		{
			begin = end;
			Sun* sun=new Sun(x + 2, y + 2 + id * 8);
			zone[id]->set_sun(sun);
			zone[id]->setfilled();
			
		}
	}

	for(auto it:zone)
		if (it->isfilled() == true && it->selected(action) == true)
		{
			it->setfree();
			it->freee();
			scor->plus(50);


		}

}

Resources::Resources()
{
	frecv = 10;
	set(5, 40);
	for (int i = 0; i < 9; i++)
		zone.push_back(new Resources_Zone(x, y + i *8));

}


Resources::~Resources()
{
}

void Resources::draw()
{

	for (auto it : zone)
		it->draw();
	
}



