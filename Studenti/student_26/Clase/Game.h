#pragma once
#include "GameTools.h"
#include "Panel.h"
#include "LogInSystem.h"
#include"Sun.h"
#include"Plant.h"
#include"Zombie.h"
#include"SunFlower.h"
#include"PeaShooter.h"
#include"WallNut.h"
#include"CherryBomb.h"
#include"SnowPeaShooter.h"
#include"RegularZombie.h"
#include"BucketHead.h"
#include"PoleVaultingZombie.h"
#include"SuperZombie.h"

#define OffsetX 13
#define OffsetY 7
#define PixelWidth 2
#define PixelHeight 2

class Game :
	public GameTools
{
public:
	Game() {
		bSelected = 0;
		Mouse.X = 0;
		Mouse.Y = 0;
		MouseOld.X = 0;
		MouseOld.Y = 0;
	};
private:
	std::wstring* PlayerName;
	Credentials user;
	std::list < Plant* > PlantList;
	std::list < Zombie* > ZombieList;
	Sun sun{ 50 ,{0,0} };
	Panel sScorePanel { 14, 8, 0, 0 };
	Panel sTopPanel{ 55, 8, OffsetX, 0 };
	Panel sSidePanel{ 14, 26, 0, OffsetY };
	Panel sMapHard{ 55, 26, OffsetX, OffsetY };
	Panel sMapMedium{ 55, 26, OffsetX, OffsetY };
	Panel sMapEasy{ 55, 26, OffsetX, OffsetY };
	Panel* pMapUsed;
	bool bSelected;
	bool bTopPanelFull;
	bool bGameLost;
	bool bGameWon;
	bool bResetGame;
	bool bAllZombiesDead;
	//Folosit sa retina Pozitia Mouse-ului la fiecare Frame
	COORD Mouse{};
	//Folosit sa retin Pozitia Mouse-ului la un anumit Moment setat
	COORD MouseOld{};
	int nNumberOfSunFlowers;
	int nNumberOfZombiesInLevel;
	int nNumberOfZombiesInMap;
	int nNumberOfLevel;
	int nZombiesKilled;
	int nPlantsPlanted;
protected:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime)override;
};

