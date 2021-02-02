#pragma once
#include<iostream>
#include"SunFlower.h"
#include"Peashooter.h"
#include"BanalZombie.h"
#include<list>


class Game;



using namespace std;


class PieceOnTable
{
private:
	list<iPlant*> listPlant;
	list<iZombie*> listZombie;
	Game* game;
public:
	PieceOnTable();
	~PieceOnTable();

	list<iPlant*> GetListPlant();

	list<iZombie*> GetListZombie();

	void Push_Back(iPlant*& plant);

	void Push_Back(iZombie*& zombie);

	void Remove_Zombie(iZombie*& zombie);

	void Remove_Plant(iPlant*& plant);

	void Connection_With_Game(Game* joc);

	Game* Get_Game();

};