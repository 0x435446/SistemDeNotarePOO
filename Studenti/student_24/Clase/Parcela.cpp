#include "Parcela.h"


int Parcela::getx()
{
	return x;
}

int Parcela::gety()
{
	return y;
}

void Parcela::freee()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = x + 1; i < x + 4; i++)
		for (int j = y + 1; j < y + 9; j++)
			conOut(i, j) << " ";



}

void Parcela::setfilled()
{
	filled = 1;
}

void Parcela::setfree()
{
	filled = 0;
}

bool Parcela::isfilled()
{
	return filled;
}

void Parcela::plant_Peashooter()
{
	plant = new Peashooter(x, y);
	plant->draw();
	plant->ability();
}

void Parcela::plant_Sunflower()
{
	plant = new Sunflower(x, y);
	plant->draw();
	plant->ability();
}

Parcela::Parcela()
{
	filled = 0;
}


Parcela::~Parcela()
{
}

Parcela::Parcela(int x, int y)
{
	this->x = x;
	this->y = y;
	filled = 0;
	plant = nullptr;
}

void Parcela::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 8; i++)
	{
		conOut(x, y + i+1) << "-";
		conOut(x + 4, y + i+1) << "-";

	}
	for (int i = 0; i <= 2; i++)
	{
		conOut(x + i + 1, y)<<"|";
		conOut(x + i + 1, y+9) << "|";

	}




}

void Parcela::draw_select()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	draw();
	conOut(x-1, y) << " selected";
}

void Parcela::delet_selected()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	draw();
	conOut(x - 1, y) << "         ";



}

void Parcela::draw_price()
{
	
}


bool Parcela::selected(std::string action)
{
	
	if (action.find("double clicked") != std::string::npos)
	{
		std::string x, y;
		for (int i = action.find("(") + 1; i < action.find(","); i++)
			x += action[i];
		for (int i = action.find(",") + 1; i < action.find(")"); i++)
			y += action[i];
		int m_x, m_y;
		m_y = stoi(x);
		m_x = stoi(y);
		if (m_x > this->x && m_x <= this->x + 4 && m_y >= this->y && m_y <= this->y + 10)
			return true;
	}
	return false;
}


void Parcela::uppdate(std::string action)
{
	if(plant!=nullptr)
	  plant->uppdate(action);


}
