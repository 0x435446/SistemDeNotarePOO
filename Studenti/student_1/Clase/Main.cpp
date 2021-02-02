#include "GameManager.h"

int main()
{
	try
	{
		GameMechanics::GameManager& gameManager = GameMechanics::GameManager::getInstance();

		gameManager.startGame();
	}
	catch (...)
	{
		Debugging::Logger::getInstance().log("Exiting game.\n");
		system("cls");
		std::cout << "A fatal error has been encountered. Please check the log file.\n";
		system("pause");
	}

	return 0;
}