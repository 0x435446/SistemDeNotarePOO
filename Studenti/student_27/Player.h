#pragma once
#include<iostream>
#include "ConsoleOutput.h"

using namespace std;

#include<string>

class Player
{
	std::string pName;
	UserInterface::ConsoleOutput output;
	std::string pPassword;
	int pScore = 0;
public:
	Player();
	Player(std::string Name,std::string Password);
	void SetScore(int score);
	int GetScore();

	string Return_User();
	~Player();
};

