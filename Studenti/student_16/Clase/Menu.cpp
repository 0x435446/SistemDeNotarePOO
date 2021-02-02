#include "Menu.h"
#include <sstream>
Menu::Menu(int bars, int mX, int mY)
	:no_of_tiles(bars), menuX(mX), menuY(mY)
{
	;
}
void Menu::addOption(std::string optName, int tr, int tc)
{
	if (!this->existentOption(optName))
	{
		menuBar.push_back(new MenuTile(optName, menuX + menuBar.size() * DISTANCE_BETWEEN_TILES, menuY, tr, tc));
	}
}
bool Menu::existentOption(std::string optName)
{
	for (int i = 0; i < this->menuBar.size(); ++i)
	{
		if (optName == this->menuBar[i]->getFunc())
		{
			return true;
		}
	}
	return false;
}
void Menu::drawMenu()
{
	for (int i = 0; i < menuBar.size(); ++i)
	{
		menuBar[i]->draw();
	}
}
std::string Menu::buttonPressed(std::string userAction)
{
	std::string action = "";
	if (userAction.find("clicked") != -1)
	{
		stringstream ss;
		ss << userAction;
		std::string parseStr;
		int x, y;
		ss >> parseStr >> parseStr >> parseStr >> parseStr  >> parseStr >> parseStr >> y >> parseStr >> x >> parseStr;
		for (int i = 0; i < this->menuBar.size(); ++i)
		{
			if (this->menuBar[i]->isPressed(x, y))
			{
				action += this->menuBar[i]->getFunc();
				return action;
			}
		}
	}
	return action;
}
void Menu::hideMenu()
{
	for (int i = 0; i < menuBar.size(); ++i)
	{
		menuBar[i]->hide();
	}
}
