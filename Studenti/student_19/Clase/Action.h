#pragma once
#include <iostream>
#include <sstream>
#include <string>


class Action
{
	std::string action;
	int x;
	int y;
public:
	Action();
	Action(std::string action);
	const std::string getAction() { return this->action; }
	const int getX() { return this->x; }
	const int getY() { return this->y; }
	~Action();
};

