#pragma once

#include <string>

namespace GameMechanics
{
	class Player

	{
	private:
		std::string name;
		std::string password;
		int level;
		int highscore;
		std::string file;
		std::string savedData;

	public:
		Player(std::string name, std::string password);
		~Player();

		void updateSavedData();
		void updateSavedData(std::string data);
		std::string getSavedData();
		int getLevel();
		std::string getName();
		int getHighscore();
		void setHighscore(int);
		void setLevel(int);
	};
}

