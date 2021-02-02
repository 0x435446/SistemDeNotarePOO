#include "GameEngine.h"
#define LEVEL 3
GameEngine*GameEngine::instance = nullptr;
GameEngine::GameEngine() {
	this->level = LEVEL;
	gameBoard = Board::GetInstance(LEVEL);
}
GameEngine& GameEngine::GetInstance() {
	if (instance == nullptr) {
		instance = new GameEngine();
	}
	return *instance;
}
void GameEngine::spawnZombie(const int &level) {
	if (Zombie::get_nextZombie()<time(nullptr)) {
		srand(time(nullptr));
		unsigned row;
		switch (level) {
		case 1:row = 3;
			break;
		case 2:row = 1 + rand() % 3;
			break;
		case 3:row = rand() % 5 + 1;
			break;
		}
		Zombie* nou = nullptr;
		unsigned type = rand() % 3;
		switch (type) {
		case 0:nou=	new ClasicZombie(row, 9);
			break;
		case 1:nou = new BHeadZombie(row, 9);
			break;
		case 2:nou = new PVZombie(row, 9);
			break;
		default:nou = nullptr;
		}
		nou->printEntity();
		gameBoard->addZombie(nou);
		Zombie::set_nextZombie(time(nullptr) + Zombie::getPeriod());
	}
}
void GameEngine::spawnResource() {
	if (Sun::get_nextSun()< time(nullptr)) {
		srand(time(NULL));
		unsigned col = rand() %9+1;
		Resources* nou = new Sun(0, col);
		nou->printEntity();
		gameBoard->addResource(nou);
		Sun::set_nextSun(time(nullptr) + Sun::getPeriod());
	}
}
bool isNumber(char* s)
{
	if (isdigit(s[0]))
	{
		return true;
	}
	else return false;
}

void GameEngine::start() {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	Plant* selectedType = nullptr;
	while (true) {
		this->spawnZombie(this->level);
		this->spawnResource();
		gameBoard->printBoard();
		std::string action = conIn.getUserActions();
		if (action != "") {
			unsigned row, col;
			if (action.find("clicked") != std::string::npos) {
				char* dup = _strdup(action.c_str());
				char* p;
				p = strtok(dup, "() ,");
				bool first = 1;
				while (p) {
					if (isNumber(p) == true && first == 1) {
						first = 0;
						col = atoi(p);
					}
					else if (isNumber(p) == true && first == 0) {
						row = atoi(p);
						break;
					}
					p = strtok(NULL, "(), ");
				}
				Plant* what = gameBoard->what_isHere(row, col);
				if (what != nullptr) {
					if (selectedType == nullptr)
						selectedType = what;
					else {
						selectedType->setCol((col - 2) / 17);
						selectedType->setRow((row - 5) / 6);
						gameBoard->addPlant(selectedType);
						selectedType->printEntity();
						selectedType = nullptr;
					}
				}
			}
			conOut(41, 2) << action;
		}
	}
}