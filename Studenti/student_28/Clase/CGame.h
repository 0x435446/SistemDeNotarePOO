#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<fstream>
#include<chrono>
#include<iostream>
#include<string>
#include<vector>
#include <time.h>
#include<chrono>
#include<thread>
#include<conio.h>
#include<stdlib.h>
#include"CEntity.h"
#include"CBoard.h"
#include"CResurse.h"
#include"DoubleClick.h"
#include<stdio.h>
#include"CPeaShooter.h"
#include"COrdinaryZombie.h"
#include"CBoardEntity.h"
#include"CSunflower.h"
#include"CBucketheadZombie.h"



class CGame
{
	static CGame *instance;
	std::vector<int>listOfPositionsResurse;
	std::vector<int>listOfPositionsPlants;
	CEntity* mat[42][155];
	int Score = 0;
	CGame();
public:
	static CGame& getInstance();
	void updateLvl(int lvl, int code, std::ofstream& filename);
	void changeScore(int key,int value);
	void getScore();
	int nrofdigits(int nr);
	void arrangeScore(int nr);
	void clearScore();
	void Start(int lvl);
	int getRandPosResurse();
	bool checkmatResurse();
	bool checkPosPlant(const int& lvl, const int& row, const int& col);
	void drawProiectil(CEntity* peashooter, CEntity* pea, const int& lvl,std::ofstream& filename);
	void moveProiectil(CEntity* sunflower, CEntity* peashooter, CEntity* ordzomb, CEntity*buckethead, CEntity* pea, const int& lvl, std::ofstream& filename);
	int getRowZombie(const int& lvl);
	int moveZombie(CEntity* sunflower, CEntity* peashooter, CEntity* pea, CEntity*ordzombie, int lvl, std::ofstream& filename);
	void addBoardToMatrix(const int& lvl);
	bool check_ordinary_zombies(int lvl, int nr);
	bool check_buckethead_zombies(int lvl, int nr);
	void clearMatrix();
	~CGame();
};

