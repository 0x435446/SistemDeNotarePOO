#include "Board.h"
Board* Board::instance = nullptr;
Board::Board(const int& level) :score(50),nextPeaShooter(time(nullptr) + 7), nextSunFlower(time(nullptr) + 5),
		nextCherryBomb(time(nullptr) + 10), nextWallNut(time(nullptr) + 20), nextSnowPea(time(nullptr) + 25){
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	for (int i = 1; i <= 171; i++) {           //barile orizontale de la sun
		conOut(2, i) << static_cast<char>(254);
		conOut(8, i) << static_cast<char>(254);
	}


	for (int i = 2; i <= 8; i++)                            //transversalele sun
		for (int j = 2; j <= 10; j++)
			conOut(i, j * 17 + 1) << static_cast<char>(254);


	for (int i = 2; i <= 37; i++) {              //barile verticale plante
		conOut(i, 1) << static_cast<char>(254);
		conOut(i, 17) << static_cast<char>(254);
	}


	for (int i = 2; i <= 6; i++)            //transversalele plante
		for (int j = 1; j <= 17; j++)
			conOut(2 + i * 6, j) << static_cast<char>(254);


	conOut(4, 5) << "Scoreboard";
	conOut(6, 8) << score;


	if (level == 3) {
		for (int i = 18; i <= 171; i++) {
			conOut(14, i) << static_cast<char>(254);
			conOut(20, i) << static_cast<char>(254);
			conOut(26, i) << static_cast<char>(254);
			conOut(32, i) << static_cast<char>(254);
			conOut(38, i) << static_cast<char>(254);
		}
	}
	if (level == 2) {
		for (int i = 18; i <= 171; i++) {//barile orizontale de la sun dar mai jos
			conOut(9, i) << "#";
			conOut(10, i) << "#";
			conOut(11, i) << "#";
			conOut(12, i) << "#";
			conOut(13, i) << "#";


			conOut(14, i) << static_cast<char>(254);
			conOut(20, i) << static_cast<char>(254);
			conOut(26, i) << static_cast<char>(254);
			conOut(32, i) << static_cast<char>(254);
			conOut(38, i) << static_cast<char>(254);


			conOut(33, i) << "#";
			conOut(34, i) << "#";
			conOut(35, i) << "#";
			conOut(36, i) << "#";
			conOut(37, i) << "#";
		}
	}
	if (level == 1) {
		for (int i = 17; i <= 171; i++) {           //barile orizontale de la sun dar mai jos
			conOut(20, i) << static_cast<char>(254);
			conOut(26, i) << static_cast<char>(254);
		}
	}

	conOut(10, 5) << "Peashooter";
	conOut(11, 8) << "100";

	conOut(16, 5) << "SunFlower";
	conOut(17, 8) << "50";


	conOut(22, 5) << "CherryBomb";
	conOut(23, 8) << "150";

	conOut(28, 5) << "Wall-Nut";
	conOut(29, 8) << "50";

	conOut(34, 5) << "SnowPea";
	conOut(35, 7) << "175";

}
Board* Board::GetInstance(const unsigned& level) {
	if (instance == nullptr) {
		instance = new Board(level);
	}
	return instance;
}
void Board::addZombie(Zombie* zombie) {
	this->zombies.push_back(zombie);
}
void Board::addResource(Resources* resource) {
	resources.push_back(resource);
}
void Board::addPlant(Plant* plant) {
	plants.push_back(plant);
}
void Board::printBoard() {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(6, 8) << score;

	100 - (nextPeaShooter - time(nullptr)) < 100 ? conOut(12, 8) << 100 - (nextPeaShooter - time(nullptr)) : conOut(12, 8) << 100;
	100 - (nextSunFlower - time(nullptr)) < 100 ? conOut(18, 8) << 100 - (nextSunFlower - time(nullptr)) : conOut(18, 8) << 100;
	100 - (nextCherryBomb - time(nullptr)) < 100 ? conOut(24, 8) << 100 - (nextCherryBomb - time(nullptr)) : conOut(24, 8) << 100;
	100 - (nextWallNut - time(nullptr)) < 100 ? conOut(30, 8) << 100 - (nextWallNut - time(nullptr)) : conOut(30, 8) << 100;
	100 - (nextSnowPea - time(nullptr)) < 100 ? conOut(36, 7) << 100-(nextSnowPea - time(nullptr)) : conOut(36, 7) << 100;
}
void Board::setScore(const unsigned& score) {
	this->score = score;
}
unsigned Board::getScore() {
	return this->score;
}
Plant* Board::what_isHere(const unsigned& row, const unsigned& col) {
	if (col >= 2 && col <= 16) {
		if (row >= 9 && row <= 14) {
			return new Peashooter();
		}
		if (row >= 15 && row <= 19) {
			return new SunFlower();
		}
		if (row >= 21 && row <= 25) {
			return new CherryBomb();
		}
		if (row >= 27 && row <= 31) {
			return new WallNut();
		}
		if (row >= 33 && row <= 37) {
			return new SnowPea();
		}
	}
	if (row >= 3 && row <= 7 && (col >= 19 && col <= 34 || col >= 36 && col <= 51 || col >= 53 && col <= 68 ||
		col >= 70 && col <= 85 || col >= 87 && col <= 102 || col >= 104 && col <= 119 ||
		col >= 121 && col <= 136 || col >= 138 && col <= 153 || col >= 155 && col <= 170)) {
		for (auto i = resources.begin(); i != resources.end(); ++i)
			if ((*i)->getRow() == 0 && (*i)->getCol() >= (col - 2) / 17 && (*i)->getCol() <= col / 17 + 1) {
				this->score += (*i)->getReward();
				(*i)->clearEntity();
				resources.erase(i);
				return nullptr;
			}
	}
}