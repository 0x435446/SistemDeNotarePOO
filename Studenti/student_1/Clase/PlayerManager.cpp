#include <fstream>
#include <string>

#include "Exception.h"
#include "Player.h"
#include "PlayerManager.h"
#include "Logger.h"

using namespace GameMechanics;

PlayerManager* PlayerManager::instance = nullptr;

PlayerManager::PlayerManager()
{
	std::ifstream f(playersSaveFile);

	if (!f.is_open())
		throw Debugging::Exception(playersSaveFile, __func__, __FILE__, __LINE__, Debugging::FILE_ERROR);

	std::string name;
	std::string password;

	while (f >> name >> password)
	{
		playerNames.push_back(name);
		playerPasswords.push_back(password);
	}

	f.close();

	Debugging::Logger::getInstance().log("Users were loaded succesfully.");
}


PlayerManager::~PlayerManager()
{
}

void GameMechanics::PlayerManager::updatePlayers(std::string name, std::string password)
{
	playerNames.push_back(name);
	playerPasswords.push_back(password);
	std::ofstream f(playersSaveFile);

	if (!f.is_open())
		throw Debugging::Exception(playersSaveFile, __func__, __FILE__, __LINE__, Debugging::FILE_ERROR);


	for (unsigned i = 0; i < playerNames.size(); i++)
		f << playerNames[i] << " " << playerPasswords[i] << "\n";

	f.close();
}

PlayerManager& PlayerManager::getInstance()
{
	if (instance == nullptr)
		instance = new PlayerManager;
	return *instance;
}

void PlayerManager::destroyInstance()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

Player * GameMechanics::PlayerManager::loadPlayer(std::string name, std::string password)
{
	if (std::find(playerNames.begin(), playerNames.end(), name) != playerNames.end())
	{
		if (std::find(playerPasswords.begin(), playerPasswords.end(), password) == playerPasswords.end())
			return nullptr;
	}
	else
		updatePlayers(name, password);

	return new Player(name, password);
}
