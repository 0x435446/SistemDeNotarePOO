#include <fstream>

#include "Player.h"

using namespace GameMechanics;

Player::Player(std::string name, std::string password)
{
	this->name = name;
	this->password = password;

	file = "Players/";
	file += name;
	file += ".txt";

	std::ifstream f(file);

	if (!f.is_open())
	{
		level = 0;
		highscore = 0;
		updateSavedData(" ");
	}
	else
	{
		f >> level;
		f >> highscore;

		std::string temp((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
		savedData = temp.substr(1);
	}

	f.close();
}


Player::~Player()
{
}


void Player::updateSavedData()
{
	std::ofstream f(file);

	f << level << "\n";
	f << highscore << "\n";
	f << savedData;

	f.close();
}

void Player::updateSavedData(std::string data)
{
	savedData = data;

	std::ofstream f(file);

	f << level << "\n";
	f << highscore << "\n";
	f << savedData;

	f.close();
}

std::string Player::getSavedData()
{
	return savedData;
}

int Player::getLevel()
{
	return level;
}

std::string GameMechanics::Player::getName()
{
	return name;
}

int GameMechanics::Player::getHighscore()
{
	return highscore;
}

void GameMechanics::Player::setHighscore(int s)
{
	highscore = s;
	updateSavedData();
}

void GameMechanics::Player::setLevel(int l)
{
	level = l;
	updateSavedData();
}
