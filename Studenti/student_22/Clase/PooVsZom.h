#pragma once
#include "engine.h"
#include "Entity.h"
#include "Plant.h"
#include "Missile.h"
#include "Zombie.h"
#include "SunFlower.h"
#include "BucketHeadZombie.h"
#include "WallNut.h"
#include "SnowPlant.h"
#include "FrozenMissile.h"
#include "PoleVaultingZombie.h"
#include "SuperZombie.h"
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <algorithm>

class PooVsZom : public engine
{
public:
	PooVsZom(int level );
	~PooVsZom();
	virtual bool onUserCreate();
	virtual bool onUserUpdate(float specialTime);
	void setSunTime(float suntTime);
	float getSunTime();
	void setLevel(int level);
	bool getWin();
	int getScor();

private:
	bool isSuper;
	bool gameOver;
	bool win;
	int zombieCounter;
	int soareCount;
	int scor;
	int level;
	bool test;
	bool onlyonce;
	float f_newPosX = 5;
	float frameScor;
	float f_newPosY = 5;
	float f_posX = 10;
	float f_posY = 10;
	float lastPozX = 0;
	int betweenOffset = 10;
	Plant *pickedPlant;
	bool isSelected;
	std::vector<int> lvl2YPos = { 2,3,4 };
	std::chrono::time_point<std::chrono::system_clock> scorTimer;
	std::chrono::time_point<std::chrono::system_clock> zombieTimer;
	//timer pt aparitia unui soare
	std::chrono::time_point<std::chrono::system_clock> sunTimer;
	//tiemr pentru aparitia unei plante aleatoare in zona de alegere
	std::chrono::time_point<std::chrono::system_clock> pickTimer;
	//lista cu plante care pot fi alese
	std::vector<Plant*> pickPlantList;
	//lista pentru soare
	std::vector<Entity*> sunList;
	//lista de proiectile aruncate
	std::vector<Missile*> missiles;
	//lista cu entitati care trebuie sa fie desenate
	std::vector<Entity*> drawList;
	//lista cu zombie care sunt in "arena"
	std::vector<Zombie*> zombieList;
	//lista cu plante care se lupta si timpul cand au fost puse in arena pt a calcula trb sa arunce un proiectil
	std::vector<std::pair<Plant* , std::chrono::time_point<std::chrono::system_clock>>> fightingPlants;
	//lista cu zombie si timpul cand s au apropiat de o planta ca sa o atace
	//exista doua posibilitati cand trb sa scot un zombie din lista, daca planta a murit sau daca zombie ul a murit
	std::vector<std::tuple<Zombie*, 
		std::chrono::time_point<std::chrono::system_clock>,
		Plant*>> fightZombies;
	std::vector<Entity*> oneTimeDraw;
	//fisier folosit pt debuging
	std::ofstream outFile;
	//lista cu pozitiile care ar trb redesenate, folosita cand "moare"/dispare o entitate
	std::vector<std::pair<float,float>> cleaningList;
	int missileCount;
	float timer;
	//timp-ul default pt aparitia unui soare
	float sunTime ;
	//lista cu plante care trb redesenate
	std::vector<Plant*> redrawPlantList;
};

/*
TO DO:
	sa mi genereze random pe lateral plante pe care sa le pun 
	sa fac in asa fel incat sa iau x ul si y ul in funtie de unde vrea utilizatorul sa puna o planta
	TREBUIE SA "TRUNCHEZ" POZITIA PLANTEI SELECTATE, sa scad pozitia actuala pana cand se termina in 0


*/
