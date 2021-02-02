#include "CBoard.h"

CBoard* CBoard::instance = nullptr;

void CBoard::draw1()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 11; i <= 154; i++)
	{
		for (int j = 6; j < 19; j++)
		{
			conOut(j, i) << static_cast<char>(178);
		}
	}
	for (int i = 11; i <= 154; i++)
	{
		for (int j = 27; j <= 40; j++)
		{
			conOut(j,i) << static_cast<char>(178);
		}
	}
	for (int i = 17; i <= 154; i+=16)
	{
		conOut(23, i) << static_cast<char>(221);
	}
	for (int i = 19; i <= 154; i += 16)
	{
		conOut(23, i) << static_cast<char>(222);
	}
}

void CBoard::draw2()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 11; i <= 154; i++)
	{
		for (int j = 6; j < 12; j++)
		{
			conOut(j, i) << static_cast<char>(178);
		}
	}
	for (int i = 11; i <= 154; i++)
	{
		for (int j = 34; j <= 40; j++)
		{
			conOut(j, i) << static_cast<char>(178);
		}
	}
	for (int i = 17; i <= 154; i += 16)
	{
		conOut(16, i) << static_cast<char>(221);
		conOut(23, i) << static_cast<char>(221);
		conOut(30, i) << static_cast<char>(221);
	}
	for (int i = 19; i <= 154; i += 16)
	{
		conOut(16, i) << static_cast<char>(222);
		conOut(23, i) << static_cast<char>(222);
		conOut(30, i) << static_cast<char>(222);
	}
}

void CBoard::drawEdges()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 1; i < 41; i++)
	{
		conOut(i, 1) << static_cast <char>(219);
		conOut(i, 10) << static_cast<char>(219);
	}
	for (int i = 1; i <= 154; i++)
	{
		conOut(1, i) << static_cast<char>(219);
		conOut(5, i) << static_cast<char>(219);
	}
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			conOut(5 + i * 7, j) << static_cast<char>(219);
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			conOut(i, j * 16 + 10) << static_cast<char>(219);
		}
	}
	for (int i = 11; i <= 154; i++)
	{
		conOut(12, i) << static_cast<char>(219);
		conOut(19, i) << static_cast<char>(219);
		conOut(26, i) << static_cast<char>(219);
		conOut(33, i) << static_cast<char>(219);
		conOut(40, i) << static_cast<char>(219);
	}
}

void CBoard::draw3()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	for (int j = 9; j <= 37; j += 7)
	{
		for (int i = 17; i <= 154; i += 16)
		{
			conOut(j, i) << static_cast<char>(221);
		}
	}
	for (int j = 9; j <= 37; j += 7)
	{
		for (int i = 19; i <= 154; i += 16)
		{
			conOut(j, i) << static_cast<char>(222);
		}
	}
}

CBoard::CBoard(const int& lvl)
{
	this->drawEdges();
	if (lvl == 1) this->draw1();
	else if (lvl == 2) this->draw2();
	else if (lvl == 3) this->draw3();
}

CBoard& CBoard::GetInstance(const int &lvl)
{
	if (instance == nullptr)
	{
		instance = new CBoard(lvl);
	}
	return *instance;
}
CBoard::~CBoard() {
	if (instance != nullptr)
		delete this->instance;
}
void CBoard::DestroyInstance()
{
	delete instance;
}
