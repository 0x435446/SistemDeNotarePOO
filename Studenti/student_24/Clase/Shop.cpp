#include "Shop.h"
#include "Parcela.h"
#include "Peashooter.h"
#include "ConsoleOutput.h"
#include "Score.h"

Shop*Shop::instance = nullptr;

int Shop::gettype()
{
	return type;
}

void Shop::settype(int x)
{
	type=x;
}

void Shop::set(int a, int b)
{
	x = a;
	y = b;
}

Shop * Shop::getinstance()
{
	if (instance == nullptr)
		instance = new Shop();
	return instance;
}

Shop::Shop()
{
	type = 0;
	set(12,5);
	for (int i = 0; i < 2; i++)
	{
		shop.push_back(new Parcela(x + i * 7, y));
		
	}


}


Shop::~Shop()
{
}

void Shop::draw()
{
	int a, b;
	//Peashooter p(13, 8);
	Peashooter p(x, y);
	Sunflower s(x+1*7, y);
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (auto it : shop)
	{
		it->draw();

	

	} 

	p.draw();
	s.draw();
	conOut(x + 4, y+3) << "100";
	conOut(x +11, y+4) << "50";
}

void Shop::uppdate(std::string action)
{
	Score*score = Score::getinstance();
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i=0;i<shop.size();i++)
		if (type == 0)
		{
			shop[i]->delet_selected();
			conOut(x + 4, y + 3) << "100";
			conOut(x + 11, y + 4) << "50";
		
			if (shop[i]->selected(action) == true )   
			{
				if (i == 0 && score->getvalue() >= 100)
				{
					type = 1;
					score->minus(100);
					shop[i]->draw_select();
				}
				else if (i == 1 && score->getvalue() >= 50)
				{
					type = 2;
					score->minus(50);
					shop[i]->draw_select();
				}
				
				conOut(x + 4, y + 3) << "100";
				conOut(x + 11, y + 4) << "50";
			}
		}
		



}
