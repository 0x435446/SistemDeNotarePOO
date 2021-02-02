#include "PieceOnTable.h"
#include"Game.h"

PieceOnTable::PieceOnTable()
{
}

PieceOnTable::~PieceOnTable()
{
}

list<iPlant*> PieceOnTable::GetListPlant()
{
	return listPlant;
}

list<iZombie*> PieceOnTable::GetListZombie()
{
	return listZombie;
}

void PieceOnTable::Push_Back(iPlant*& plant)
{
	listPlant.push_back(plant);
}

void PieceOnTable::Push_Back(iZombie*& zombie)
{
	listZombie.push_back(zombie);
}

void PieceOnTable::Remove_Zombie(iZombie*& zombie)
{
	listZombie.remove(zombie);
}

void PieceOnTable::Remove_Plant(iPlant*& plant)
{
	listPlant.remove(plant);
}

void PieceOnTable::Connection_With_Game(Game* joc)
{
	game = joc;
}

Game* PieceOnTable::Get_Game()
{
	return game;
}
