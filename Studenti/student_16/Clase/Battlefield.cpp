#include "Battlefield.h"
#include "Sunflower.h"
#include "PeaShooter.h"
#include "WallNut.h"
#include "CherryBomb.h"
#include <stdlib.h>
#include "Zombie.h"
#include "Log.h"
Battlefield* Battlefield::instance = nullptr;
Battlefield& Battlefield::getInstance(int difficulty)
{
	if (!Battlefield::instance)
	{
		Battlefield::instance = new Battlefield(difficulty);
	}
	return *Battlefield::instance;
}
Battlefield::Battlefield(int difficulty)
	:difficulty(difficulty)
{
	this->startX = 7;
	this->startY = 20;
	int size=0;
	if (difficulty == 1)size = 1;
	if (difficulty == 2)size = 3;
	if (difficulty == 3)size = 5;
	for (int i = 0; i < size; ++i)
	{
		this->fieldLines.push_back(new BattleLine(this->startX+((5-size)/2+i)*TILE_HEIGHT,this->startY));
	}
	this->genRegular = steady_clock::now();
	this->genBucket = steady_clock::now();
	this->genVaulting = steady_clock::now();
}
void Battlefield::draw()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->startX, this->startY) << (unsigned char)TL;
	conOut(this->startX, this->startY + 8 * TILE_WIDTH) << (unsigned char)TR;
	conOut(this->startX + 5 * TILE_HEIGHT, this->startY) << (unsigned char)BL;
	conOut(this->startX + 5 * TILE_HEIGHT, this->startY + 8 * TILE_WIDTH) << (unsigned char)BR;
}
int Battlefield::executeFunction()
{

	this->draw();
	auto end = steady_clock::now();
	int score = 0;
	if (duration_cast<milliseconds>(end - this->genRegular).count() > 20000)
	{
		this->genRegular = end;
		srand(unsigned(time(0)));
		int gen = rand() % this->fieldLines.size();
		this->fieldLines[gen]->addZombie("Zombie");
		Log::getInstance().updateLog("A fost creat un obiect de tip Zombie");
	}
	if (duration_cast<milliseconds>(end - this->genBucket).count() > 50000)
	{
		this->genBucket = end;
		srand(unsigned(time(0)));
		int gen = rand() % this->fieldLines.size();
		this->fieldLines[gen]->addZombie("BucketHeadZombie");
		Log::getInstance().updateLog("A fost creat un obiect de tip BucketHeadZombie");
	}
	if (duration_cast<milliseconds>(end - this->genVaulting).count() > 45000)
	{
		this->genVaulting = end;
		srand(unsigned(time(0)));
		int gen = rand() % this->fieldLines.size();
		this->fieldLines[gen]->addZombie("PoleVaultingZombie");
		Log::getInstance().updateLog("A fost creat un obiect de tip BucketHeadZombie");
	}
	for (int i = 0; i < this->fieldLines.size(); ++i)
	{
		score+=this->fieldLines[i]->executeFunction();
	}
	return score;
}
int Battlefield::pressedInside(int x, int y)
{
	for (int i = 0; i < this->fieldLines.size(); ++i)
	{
		if (this->fieldLines[i]->pressedOnTile(x, y) != -1)
		{
			return i * 8 + this->fieldLines[i]->pressedOnTile(x, y);
		}
	}
	return -1;
}
bool Battlefield::addPlant(int position, std::string plantName)
{
	int pos = position/8;
	if (this->fieldLines.size() == 3)
		pos += 1;
	if (this->fieldLines.size() == 1)
	{
		pos += 2;
	}
	if (plantName == "Sunflower")
	{
		Plant* p = new Sunflower(this->startX+pos*TILE_HEIGHT, this->startY+(position%8)*TILE_WIDTH);
		if (this->fieldLines[position / 8]->addPlant(position % 8, p))
		{
			Log::getInstance().updateLog("A fost creat un obiect de tip "+plantName);
			return true;
		}
		else
		{
			delete p;
			return false;
		}
	}
	if (plantName == "PeaShooter")
	{
		Plant* p = new PeaShooter(this->startX + pos * TILE_HEIGHT, this->startY + (position % 8) * TILE_WIDTH);
		
		if (this->fieldLines[position/8]->addPlant(position % 8, p))
		{
			Log::getInstance().updateLog("A fost creat un obiect de tip " + plantName);
			return true;
		}
		else
		{
			delete p;
			return false;
		}
	}
	if (plantName == "WallNut")
	{
		Plant* p=new WallNut(this->startX + pos * TILE_HEIGHT, this->startY + (position % 8) * TILE_WIDTH);
		if (this->fieldLines[position / 8]->addPlant(position % 8, p))
		{
			Log::getInstance().updateLog("A fost creat un obiect de tip " + plantName);
			return true;
		}
		else
		{
			delete p;
			return false;
		}
	}
	if (plantName == "CherryBomb")
	{
		Plant* p = new CherryBomb(this->startX + pos * TILE_HEIGHT, this->startY + (position % 8) * TILE_WIDTH);
		if (this->fieldLines[position / 8]->addPlant(position % 8, p))
		{
			Log::getInstance().updateLog("A fost creat un obiect de tip " + plantName);
			return true;
		}
		else
		{
			delete p;
			return false;
		}
	}
}
bool Battlefield::getSuns(int x, int y)
{
	for (int i = 0; i < this->fieldLines.size(); ++i)
	{
		if (this->fieldLines[i]->pressedOnTile(x, y)!=-1)
		{
			return this->fieldLines[i]->getSuns(x, y);
		}
	}
	return false;
}
bool Battlefield::testLoss()
{
	for (int i = 0; i < this->fieldLines.size(); ++i)
	{
		if (!this->fieldLines[i]->getLife())
		{
			return true;
		}
	}
	return false;
}