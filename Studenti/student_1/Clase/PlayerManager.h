#pragma once

#include <vector>

#include "Player.h"

namespace GameMechanics
{
	class PlayerManager
	{
	private:
		const char* playersSaveFile = "Players/PlayersList.txt";

		PlayerManager();
		PlayerManager(PlayerManager&);
		~PlayerManager();

		static PlayerManager* instance;

		std::vector<std::string> playerNames;
		std::vector<std::string> playerPasswords;
		void updatePlayers(std::string, std::string);

	public:
		static PlayerManager& getInstance();
		static void destroyInstance();

		Player* loadPlayer(std::string name, std::string password);
	};
}