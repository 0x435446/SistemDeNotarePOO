#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include <fstream>
#include "Player.h"
#include "BattleField.h"
#include "ResourceFactory.h"
#include "ZombieFactory.h"
#include "Exception.h"

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	 5

using namespace std::chrono;

void ZombiesProduction()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::GetInstance();
	BattleField* battlefield = BattleField::GetInstance();
	ZombieFactory* zombie_factory = ZombieFactory::GetInstance();
	static auto begin_zombie = steady_clock::now();
	auto end_zombie = steady_clock::now();
	if (duration_cast<milliseconds>(end_zombie - begin_zombie).count() > 3000)
	{
		begin_zombie = end_zombie;
		zombie_factory->CreateZombie();
		switch (battlefield->GetLevel())
		{
		case LVL1:
			for (int i = 18; i < 24; i++)
				for (int j = 16; j < 161; j++)
					conOut(i, j) << battlefield->GetChar(i, j);
			break;
		case LVL2:
			for (int i = 12; i < 30; i++)
				for (int j = 16; j < 161; j++)
					conOut(i, j) << battlefield->GetChar(i, j);
			break;
		case LVL3:
			for (int i = 6; i < 36; i++)
				for (int j = 16; j < 161; j++)
					conOut(i, j) << battlefield->GetChar(i, j);
			break;
		}
	}
}

void ResourcesProduction()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::GetInstance();
	BattleField* battlefield = BattleField::GetInstance();
	ResourceFactory* resource_factory = ResourceFactory::GetInstance();
	static auto begin_resource = steady_clock::now();
	auto end_resource = steady_clock::now();
	if (duration_cast<milliseconds>(end_resource - begin_resource).count() > 3000)
	{
		begin_resource = end_resource;
		resource_factory->CreateResource();
		for (int i = 0; i < 6; i++)
			for (int j = 17; j < 160; j++)
				conOut(i, j) << battlefield->GetChar(i, j);
	}
}

int main()
{	
	try
	{
		bool found = false;
		int lvl;
		std::string username;
		std::string username_check;
		std::string filename = "usernames.txt";
		std::fstream file;

		std::cout << std::endl << "\tUsername: ";
		std::cin >> username;

		file.open(filename);
		while (file >> username_check)
		{
			if (username == username_check)
				found = true;
		}
		file.close();

		std::cout << std::endl << "\tLevel?[1/2/3]";
		std::cin >> lvl;

		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::GetInstance();
		UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::GetInstance();
		Player* player = new Player(username);
		BattleField* battlefield = BattleField::GetInstance(Level(lvl));
		for (int i = 0; i < 37; i++)
			for (int j = 0; j < 161; j++)
				conOut(i, j) << battlefield->GetChar(i, j);

		while (true)
		{
			ResourcesProduction();
			ZombiesProduction();

			std::string action = conIn.GetUserActions();
			if (action != "")
			{
				conOut(41, 2) << action;
			}
			conOut(41, 145) << "Resources: " << player->GetResources();
		}

		ResourceFactory* resources_factory = ResourceFactory::GetInstance();
		ResourceFactory::DeleteInstance(resources_factory);

		ZombieFactory* zombies_factory = ZombieFactory::GetInstance();
		ZombieFactory::DeleteInstance(zombies_factory);

		BattleField::DeleteInstance(battlefield);
		delete player;

		return 0;
	}
	catch (Exception exception)
	{
		std::cout << exception;
	}
}