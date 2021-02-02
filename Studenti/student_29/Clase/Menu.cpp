#include "Menu.h"

Menu* Menu::instance = nullptr;

using namespace std::chrono;

Menu::Menu()
{

}

Menu& Menu::getMenu()
{
	if (!instance)
		instance = new Menu();
	return *instance;
}

void Menu::printLogo()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);

	std::ifstream logo("poovszombies.txt");
	char* line = new char[256];
	int i = 17;
	while (logo.getline(line, 256))
	{
		conOut(i, 50) << line;
		i++;
	}

	conOut(27, 60) << "  Write your name using the keyboard and after that";
	conOut(28, 60) << "           (Press space when you`re done)         ";

	while (1)
	{
		conOut(29, 70) << "Click the screen to continue...";
		conOut(29, 70) << "                               ";
		static auto begin = steady_clock::now();
		int counter = 0;
		auto end = steady_clock::now();

		if (duration_cast<seconds>(end - begin).count() > 2)
		{
			begin = end;
			counter++;
			if (counter % 2 == 0)
			{
				conOut(29, 70) << "Click the screen to continue...";
			}
			else
			{
				conOut(29, 70) << "                               ";
			}
		}
		
		//std::string action = conIn.getUserActions();
		if (/*action.find("click") != std::string::npos &&*/ playerName != " ")
		{
			system("cls");
			break;
		}

		conOut(30, 70);
		std::cin >> playerName;
		conOut(40, 0);
		std::cout << "Username: " << playerName;
		conOut(32, 70);
		system("pause");
	}

	logo.close();

	conOut.deleteConOut();
	conIn.deleteConIn();

	SetConsoleTextAttribute(hConsole, 7);
}

void Menu::printGameOver()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);

	std::ifstream over("gameover.txt");
	char* line = new char[256];
	int i = 13;
	while (over.getline(line, 256))
	{
		conOut(i, 60) << line;
		i++;
	}

	over.close();

	conOut.deleteConOut();
	conIn.deleteConIn();

	Sleep(5000);
	exit(0);
}

void Menu::printPlayerWon()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);

	std::ifstream over("win.txt");
	char* line = new char[256];
	int i = 13;
	while (over.getline(line, 256))
	{
		conOut(i, 42) << line;
		i++;
	}

	over.close();

	conOut.deleteConOut();
	conIn.deleteConIn();

	Sleep(5000);
	exit(0);
}

void Menu::initializeGame()
{
	printLogo();
	loadingMenu();

	std::ifstream infile("players.txt");
	std::ofstream outfile;

	if (infile.is_open())
	{
		infile.close();
		outfile.open("players.txt", std::ios_base::app);
		outfile << playerName << "\n";
		outfile.close();
	}
	else
	{
		outfile.open("players.txt", std::ios_base::out);
		outfile << playerName << "\n";
		outfile.close();
	}

	Game& game = Game::getGame();
	game.startGame();
	int whoWon = game.returnWhoWon();
	if (whoWon)
	{
		printPlayerWon();
	}
	else
	{
		printGameOver();
	}
}

void Menu::loadingMenu()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";

	auto timeStart = clock();
	int ok = 1;
	while (true)
	{
		if (ok)
		{
			doLoadingMenuBar();
		}

		std::string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(41, 0) << action;
		}
		if ((clock() - timeStart) / CLOCKS_PER_SEC >= 3) // time in seconds
		{
			conIn.deleteConIn();
			conOut.deleteConOut();
			break;
		}
	}
	system("cls");
}

void Menu::doLoadingMenuBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
			if (printedChar == "*")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "*";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_STARS;
		}
	}
}

Menu::~Menu()
{
}
