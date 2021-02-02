#pragma once
#include "iGame.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include<Windows.h>
#include<iostream>
#include"Player.h"
#include<thread>
#include"Sun.h"
#include"SunFlower.h"
#include<list>
#include"iPlant.h"
#include"Peashooter.h"
#include"PieceOnTable.h"
#include"BucketHead_Zombie.h"

#define FIRST_ROW 5
#define FIRST_COL 5

using namespace std;

class Game :
	public iGame
{
private:
	Sun* sun=new Sun();
	SunFlower* firstSunFlower = new SunFlower();
	Peashooter* firstPeaShooter = new Peashooter();
	PieceOnTable* piece_table;
	Player* ply;

	int nivel = 1;

	int another_player = 1;

	int Score = 0;

public:
	Game();
	~Game();

	void Create_First_Sun_Flower();

	void Put_Sun_Flower_On_The_Table(int xPos, int yPos,int &push);

	void Put_Sun_PeaShooter_On_The_Table(int xPos, int yPos,int & push);

	//void TryToShoot();

	void Create_First_PeaShooter();

	void Listen();

	void ShowNivel();

	void NextLevel();

	void Win();

	void ShowScore();

	void AddScore(int score);

	void Create_User_Password();

	void Put_Player_in_File();
	//list<iPlant*> getListPlant();
};

