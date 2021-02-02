#include "Sun.h"
#include "ConsoleOutput.h"


Sun::Sun()
{
	
	

}

Sun::Sun(int a, int b)
{
	bonus = 50;
	x = a;
	y = b;
	

}


Sun::~Sun()
{
}


void Sun::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << "  ^  ";
	conOut(x+1, y) << "< O >";
	conOut(x+2, y) << "  v  ";

	


}

void Sun::uppdate(std::string)
{
}
