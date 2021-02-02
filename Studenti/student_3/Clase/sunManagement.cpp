#include "sunManagement.h"

sunManagement * sunManagement::instance = nullptr;

sunManagement & sunManagement::getInstance()
{
	// TODO: insert return statement here
	if (instance == nullptr) instance = new sunManagement;
	return *instance;
}

void sunManagement::addSun()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	srand((unsigned int)time(NULL));
	int c = rand() % 8;
	if (getVector(c) != 0)
		setVector(c);
	switch (c)
	{
	case 0:
	{
		conOut(3,25) << "Soare";
		break;
	}
	case 1:
	{
		conOut(3, 45) << "Soare";
		break;
	}
	case 2:
	{
		conOut(3, 65) << "Soare";
		break;
	}
	case 3:
	{
		conOut(3, 85) << "Soare";
		break;
	}
	case 4:
	{
		conOut(3, 105) << "Soare";
		break;
	}
	case 5:
	{
		conOut(3, 125) << "Soare";
		break;
	}
	case 6:
	{
		conOut(3, 145) << "Soare";
		break;
	}
	case 7:
	{
		conOut(3, 165) << "Soare";
		break;
	}
	default:
		Log::getInstance().displayMessage("Eroare initializere soare.\n");
		break;
	}
}

void sunManagement::deleteSun(int i)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	switch (i)
	{
	case 0:
	{
		sunVector[0] = 0;
		conOut(3, 25) << "     ";
		break;
	}
	case 1:
	{
		sunVector[1] = 0;
		conOut(3, 45) << "     ";
		break;
	}
	case 2:
	{
		sunVector[2] = 0;
		conOut(3, 65) << "     ";
		break;
	}
	case 3:
	{
		sunVector[3] = 0;
		conOut(3, 85) << "     ";
		break;
	}
	case 4:
	{
		sunVector[4] = 0;
		conOut(3, 105) << "     ";
		break;
	}
	case 5:
	{
		sunVector[5] = 0;
		conOut(3, 125) << "     ";
		break;
	}
	case 6:
	{
		sunVector[6] = 0;
		conOut(3, 145) << "     ";
		break;
	}
	case 7:
	{
		sunVector[7] = 0;
		conOut(3, 165) << "     ";
		break;
	}
	default:
		Log::getInstance().displayMessage("Eroare stergere soare.\n");
		break;
	}
}
