#include "Action.h"
#include <conio.h>


Action::Action()
{
}

Action::Action(std::string action)
{
	std::string aux;
	std::string nr;
	std::istringstream iss(action);
	do
	{
		iss >> aux;
		if (aux == "clicked")
		{
			this->action = aux;
			iss >> aux;
			iss >> aux;
			this->x = std::stoi(aux);
			iss >> aux;
			this->y = std::stoi(aux);
		}
	} while (iss);
}


Action::~Action()
{
}
