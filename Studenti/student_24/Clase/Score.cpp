#include "Score.h"
#include  "ConsoleOutput.h"

 Score*Score::instance = nullptr;

 int Score::getvalue()
 {
	 return value;
 }

 void Score::plus(int x)
{
	
	value = value + x;


}

void Score::minus(int x)
{
	value = value - x;
}

Score * Score::getinstance()
{
	if (instance == nullptr)
		instance = new Score;
	return instance;
}



Score::Score()
{
	value = 50;
}


Score::~Score()
{ 

	
}

void Score::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 7; i < 10; i++)
	{
		conOut(i, 19) << "||";
		conOut(i, 35) << "||";
	}
	for (int i = 20; i < 35; i++)
	{
		conOut(6, i) << "==";
		conOut(10, i) << "==";
	}
	
	uppdate("blabla");
	
}

void Score::uppdate(std::string)
{
 	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(8, 27) << "   ";
	if (value > 99)
		conOut(8, 27) << value;
	else
		conOut(8, 28) << value;






}
