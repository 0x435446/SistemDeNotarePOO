#pragma once

#include <map>

#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "GameSpecifications.h"
#include "Sprite.h"

namespace UserInterface
{
	class Sprite;

	class GUI
	{
	private:
		GUI();
		GUI(GUI&);
		~GUI();

		static GUI* gui;

		ConsoleInput& conIn;
		ConsoleOutput& conOut;
		std::map<GameMechanics::EntityID, Sprite*> sprites;

		void loadSprites();
		void initialiseWindow();

	public:
		static GUI& getInstance();
		static void destroyInstance();

		std::string getPlayerInfo(std::string);

		void drawInfo(std::string, int);
		void showLevelNo(int);
		void showGameStatus(GameMechanics::GameStatus);
		Sprite* getSprite(GameMechanics::EntityID);
		void updateInfo(int, int, int, int, int, bool);
		std::string getMouseEvent();
		void updatePlantsStatus(std::map<GameMechanics::EntityID, GameMechanics::PlantStatus>);
		void drawLane(unsigned rowUp, unsigned colLeft);
		void eraseTile(unsigned rowUp, unsigned colLeft);
		void eraseProjectile(unsigned rowUp, unsigned colLeft);
		void cleanBoard();
	};
}
