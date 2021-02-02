#include "MenuTile.h"
#include "ConsoleOutput.h"
MenuTile::MenuTile(std::string func, int sX, int sY, int tr, int tc)
	:func(func), startX(sX), startY(sY), isVisible(true), shown(false), rows(tr), cols(tc)
{
	if (func == "Play" || func == "Back")
	{
		startY += 15;
	}
	std::vector<unsigned char> tROW0;
	tROW0.push_back(201);
	for (int j = 1; j < tc - 1; ++j)
	{
		tROW0.push_back(205);
	}
	tROW0.push_back(187);
	mat.push_back(tROW0);
	std::vector<unsigned char> tROW1;
	tROW1.push_back(186);
	for (int j = 0; j < (tc - 2 - this->func.size()) / 2; ++j)
	{
		tROW1.push_back(32);
	}
	for (int j = 0; j < this->func.size(); ++j)
	{
		tROW1.push_back(this->func[j]);
	}
	for (int j = 0; j < (tc - 2 - this->func.size()) / 2; ++j)
	{
		tROW1.push_back(32);
	}
	tROW1.push_back(186);
	for (int i = 1; i < tr - 1; ++i)
	{
		mat.push_back(tROW1);
	}
	std::vector<unsigned char> tROW2;
	tROW2.push_back(200);
	for (int j = 1; j < tc - 1; ++j)
	{
		tROW2.push_back(205);
	}
	tROW2.push_back(188);
	mat.push_back(tROW2);

}

void MenuTile::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < this->rows; ++i)
	{
		for (int j = 0; j < this->cols; ++j)
		{
			conOut(this->startX + i, this->startY + j) << this->mat[i][j];
		}
	}
	this->isVisible = true;
}

void MenuTile::hide()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < this->rows; ++i)
	{
		for (int j = 0; j < this->cols; ++j)
		{
			conOut(this->startX + i, this->startY + j) << " ";
		}
	}
	this->isVisible = false;
}

bool MenuTile::isPressed(int x, int y)
{
	if (this->isVisible)
	{
		if (x >= this->startX && x <= this->startX + this->rows - 1)
		{
			if (y >= this->startY && y <= this->startY + this->cols - 1)
			{
				return true;
			}
		}
	}
	return false;
}