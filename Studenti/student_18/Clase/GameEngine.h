#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Board.h"
#include<fstream>
#include <iostream>
#include <locale>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstring>
class GameEngine
{
	GameEngine();
	virtual ~GameEngine() {}

	std::string user;
	unsigned level;


	static GameEngine* instance;


	Board* gameBoard;


	void spawnZombie(const int&);
	void spawnResource();
public:
	void start();
	static GameEngine& GetInstance();
};