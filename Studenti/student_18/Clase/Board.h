#pragma once
#include"ClasicZombie.h"
#include"PVZombie.h"
#include"BHeadZombie.h"
#include"Peashooter.h"
#include"SunFlower.h"
#include"CherryBomb.h"
#include"WallNut.h"
#include"SnowPea.h"
#include"Sun.h"
#include<time.h>
#include<list>
class Board
{
	unsigned score;
	std::list<Zombie*>zombies;
	std::list<Plant*>plants;
	std::list<Resources*>resources;
	Board(const int&);
	static Board* instance;

	time_t nextPeaShooter;
	time_t nextSunFlower;
	time_t nextCherryBomb;
	time_t nextWallNut;
	time_t nextSnowPea;
public:
	static Board* GetInstance(const unsigned&);
	void addZombie(Zombie*);
	void addResource(Resources*);
	void addPlant(Plant*);


	Plant* what_isHere(const unsigned&,const unsigned&);


	void printBoard();


	void setScore(const unsigned&);
	unsigned getScore();


	void set_nextPeaShooter(const time_t& time) { this->nextPeaShooter = time; }
	time_t get_nextPeaShooter() { return this->nextPeaShooter; }

	void set_nextSunFlower(const time_t& time) { this->nextSunFlower = time;; }
	time_t get_nextSunFlower() { return this->nextSunFlower; }

	void set_nextCherryBomb(const time_t& time) { this->nextCherryBomb = time; }
	time_t get_nextCherryBomb() { return this->nextCherryBomb; }

	void set_nextWallNut(const time_t& time) { this->nextWallNut = time; }
	time_t get_nextWallNut() { return this->nextWallNut; }

	void set_nextSnowPea(const time_t& time) { this->nextSnowPea = time; }
	time_t get_nextSnowPea() { return this->nextSnowPea; }

};

