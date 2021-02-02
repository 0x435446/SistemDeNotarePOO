#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include "Scoreboard.h"
#include "ResourceGrid.h"
#include "Sunflower.h"
#include "PlantShop.h"
#include "Zombie.h"
#include "Battlefield.h"
#include "Menu.h"
#include <sstream>
#include <chrono>

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5
		
#define COL_POSITION 81
#define ROW_MENU 10
#define ROW_SCORE 30


using namespace std::chrono;
namespace ParseCoordinates
{
	void getCoordinates(string info,vector<int>& coord)
	{
		stringstream ss(info);
		string word;
		int x, y;
		ss >> word >> word >> word >> word >> word >> word >> y >> word >> x >> word;
		coord.push_back(x);
		coord.push_back(y);
	}
}
bool isUser(std::string name, std::string password)
{
	std::ifstream fin("credentials.txt");
	char nume[30], parola[30];
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> nume >> parola;
			if (name.compare(nume) == 0 && password.compare(parola) == 0)
			{
				fin.close();
				return true;
			}
		}
	}
	fin.close();
	return false;
}
void logIn(int x, int y, vector<string>& credentials)
{
	credentials.clear();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	std::string action = conIn.getUserActions();
	std::string user = "", pass = "";
	int col = 0;
	while (action != "Enter" && action != "Space")
	{
		if (action != "" && action.find("Mouse") == -1)
		{
			conOut(x + 1, y + col) << action;
			user += action;
			col++;
		}
		action = conIn.getUserActions();
	}
	col = 0;
	action = conIn.getUserActions();
	while (action != "Enter" && action != "Space")
	{
		if (action != "" && action.find("Mouse") == -1)
		{
			conOut(x + 5, y + col) << "*";
			pass += action;
			col++;
		}
		action = conIn.getUserActions();
	}
	credentials.push_back(user);
	credentials.push_back(pass);
}
void loadResource(vector<string>& load)
{
	std::ifstream fin("loadingScreen.txt");
	int line = 0;
	char buff[1024];
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(buff, 1024);
			line++;
			load.push_back(std::string(buff));
		}
	}
	fin.close();
}
bool test_credentials(vector<string> credentials)
{
	std::ifstream fin("credentials.txt");
	char nume[32], parola[32];
	while (!fin.eof())
	{
		fin >> nume >> parola;
		if (credentials[0] == string(nume) && credentials[1] == string(parola))
		{
			fin.close();
			return true;
		}
	}
	fin.close();
	return false;
}
void add_credentials(vector<string>credentials)
{
	std::ofstream fout("credentials.txt", ios::app);
	fout << "\n" << credentials[0] << " " << credentials[1];
	fout.close();
}
void loadingScreen(vector<string>load)
{
	static auto begin = steady_clock::now();
	static int index = 0;
	static bool passed = false;
	static int passes = 0;
	while (passes <= 7)
	{
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		auto end = steady_clock::now();
		std::string alternativeLine = "";
		for (int i = 0; i < 115; ++i)
			alternativeLine += " ";
		std::string line = "";
		if (duration_cast<milliseconds>(end - begin).count() > 130)
		{
			begin = end;
			if (passed)
			{
				line = alternativeLine;
			}
			else
			{
				line = load[index];
			}
			conOut(15 + index, 30) << line;
			index++;
			if (index == load.size())
			{
				index = 0;
				passed = !passed;
				passes++;
			}
		}
	}
}
void doMenu(bool& exited, bool& play)
{
	Menu mainMenu(4, ROW_MENU, COL_POSITION);
	while (!exited)
	{
		UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
		UserInterface::ConsoleInput& conIn = UserInterface::ConsoleInput::getInstance();
		mainMenu.addOption("Logare", 3, 14);
		mainMenu.addOption("New User", 3, 14);
		mainMenu.addOption("Scoreboard", 3, 14);
		mainMenu.addOption("Exit", 3, 14);
		mainMenu.drawMenu();
		static bool score = false;
		static bool login = false;
		std::string action = conIn.getUserActions();
		std::string userAction = mainMenu.buttonPressed(action);
		if (userAction != "")
		{
			if (userAction == "Exit")
			{
				exited = true;
				mainMenu.hideMenu();
			}
			else if (userAction == "Scoreboard")
			{
				if (!score)
				{
					conOut(ROW_SCORE - 1, COL_POSITION - 1) << "Tabela de scor : ";
				}
				else
				{
					conOut(ROW_SCORE - 1, COL_POSITION - 1) << "                 ";
				}
				std::ifstream fin("score.txt");
				char nume[32];
				int scor;
				int i = 1;
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> nume >> scor;
						if (!score)
						{
							conOut(ROW_SCORE + i, COL_POSITION) << i << ". " << nume << " " << scor;
						}
						else
						{
							conOut(ROW_SCORE + i, COL_POSITION) << "                    ";
						}
						++i;
					}
				}
				score = !score;
				fin.close();
			}
			else
			{
				if (!login)
				{
					mainMenu.hideMenu();
					Menu secondMenu(3, ROW_MENU, COL_POSITION - 15);
					secondMenu.addOption("Username", 3, 14);
					secondMenu.addOption("Parola", 3, 14);
					secondMenu.addOption("Play", 3, 14);
					secondMenu.addOption("Back", 3, 14);
					bool back = false;
					secondMenu.drawMenu();
					vector<string> credentials;
					logIn(ROW_MENU, COL_POSITION, credentials);
					if (userAction == "Logare")
					{
						while (!test_credentials(credentials))
						{
							conOut(ROW_MENU - 2, COL_POSITION - 8) << "User si/sau parola gresite!";
							conOut(ROW_MENU + 1, COL_POSITION) << "              ";
							conOut(ROW_MENU + 5, COL_POSITION) << "              ";
							logIn(ROW_MENU, COL_POSITION, credentials);
						}

					}
					else
					{
						if (!test_credentials(credentials))
						{
							add_credentials(credentials);
						}
					}
					conOut(ROW_MENU - 2, COL_POSITION - 8) << "Credentiale corecte, puteti apasa Play";
					conOut(ROW_MENU + 1, COL_POSITION) << "              ";
					conOut(ROW_MENU + 5, COL_POSITION) << "              ";
					while (!play && !back)
					{
						action = conIn.getUserActions();
						userAction = secondMenu.buttonPressed(action);
						if (userAction == "Play")
						{
							play = true;
							exited = true;
							secondMenu.hideMenu();
						}
						if (userAction == "Back")
						{
							back = true;
							secondMenu.hideMenu();
							mainMenu.drawMenu();
						}
					}
					conOut(ROW_MENU - 2, COL_POSITION - 8) << "                                      ";
				}
				login = !login;
			}
		}
	}

}

int main(void)
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput& conIn = UserInterface::ConsoleInput::getInstance();
	Scoreboard& score = Scoreboard::getInstance();
	ResourceGrid& resources = ResourceGrid::getInstance();
	PlantShop& shop = PlantShop::getInstance();
	//AICI SE SETEAZA DIFICULTATEA//
	Battlefield& field = Battlefield::getInstance(1); //1. 1 pentru o linie , 2 pentru 3 linii si 3 pentru 5 linii
	//////////////////////////////
	for (int i = 0; i < 5; ++i)
	{
		resources.addSun();
	}
	bool exited = false;
	bool play = false;
	while (!exited)
	{
		doMenu(exited, play);
	}
	vector<string> screen;
	loadResource(screen);
	while (true&&play)
	{
		loadingScreen(screen);
		string action = conIn.getUserActions();
		if (action != "")
		{
			vector<int>coord;
			ParseCoordinates::getCoordinates(action, coord);
			conOut(41, 2) << coord[0] << ", " << coord[1]<<"                  ";
			if (action.find("clicked") != -1)
			{
				int index = shop.getAvatarIndex(coord);
				if (index != -1)
				{
					action = conIn.getUserActions();
					while (action.find("clicked") == -1)
					{
						vector<int>scoord;
						action = conIn.getUserActions();
						ParseCoordinates::getCoordinates(action, scoord);
						if (action.find("clicked") != -1)
						{
							if (field.pressedInside(scoord[0], scoord[1]) != -1)
							{
								if (field.addPlant(field.pressedInside(scoord[0], scoord[1]), shop.getAvatarName(index)))
								{
									resources.modifyMoney(shop.getAvatarCost(index));
									shop.removeAvatar(index);
								}
							}
						}

					}
				}
				int position = field.pressedInside(coord[0], coord[1]);
				if (resources.getMoney()<8)
				{
					if (position != -1)
					{
						if (field.getSuns(coord[0], coord[1]))
						{
							resources.addSun();
						}
					}
				}
			}
		}
		resources.draw();
		score.draw();
		shop.executeFunction();
		score.modifyCount(field.executeFunction());
		if (field.testLoss())
		{
			score.updateScore("Dragos");
			break;
		}
	}
	return 0;
} 

