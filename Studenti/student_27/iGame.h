#pragma once
#include<iostream>
#include<list>

class iPlant;

class Game;

using namespace std;

class iGame
{
public:
	iGame() { ; };
	~iGame() { ; };

	static Game* get_instance();

	virtual void Listen()=0;
	//virtual list<iPlant*> getListPlant() = 0;
};