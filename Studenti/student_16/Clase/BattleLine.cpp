#include "BattleLine.h"
#include "Sunflower.h"
#include "Proiectil.h"
#include "Log.h"
BattleLine::BattleLine(int sX, int sY)
{
	this->startX = sX;
	this->startY = sY;
	for (int i = 0; i < 8; ++i)
	{
		this->plantTiles.push_back(new BattleTile(this->startX, this->startY + i * TILE_WIDTH));
	}
}
void BattleLine::drawHeart()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	std::ifstream fin("heart.txt");
	char buff[1024];
	int j = 1;
	while (!fin.eof())
	{
		fin.getline(buff, 1024);
		conOut(this->startX + j+1, this->startY - 4) << buff;
		j++;
	}
	fin.close();
}
void BattleLine::draw()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	//this->drawHeart();
	for (int i = 0; i < this->plantTiles.size(); ++i)
	{
		this->plantTiles[i]->draw();
	}
}
int BattleLine::pressedOnTile(int x, int y)
{
	for (int i = 0; i < this->plantTiles.size(); ++i)
	{
		if (this->plantTiles[i]->pressedInside(x,y))
		{

			return i;
		}
	}
	return -1;
}
void BattleLine::addZombie(std::string type)
{
	if (type == "Zombie")
	{
		this->enemies.push_back(new Zombie(this->startX, this->startY + 8 * TILE_WIDTH - 5, "Zombie"));
	}
	if (type == "BucketHeadZombie")
	{
		this->enemies.push_back(new BucketHeadZombie(this->startX, this->startY + 8 * TILE_WIDTH - 5));
	}
	if (type == "PoleVaultingZombie")
	{
		this->enemies.push_back(new PoleVaultingZombie(this->startX, this->startY + 8 * TILE_WIDTH - 5));
	}
}
int BattleLine::executeFunction()
{
	int score = 0;
	for (int i = 0; i < this->plantTiles.size(); ++i)
	{
		if (this->plantTiles[i]->getPlant())
		{
			for (int j = 0; j < this->enemies.size(); ++j)
			{
				if (this->plantTiles[i]->getPlant() && this->plantTiles[i]->getPlant()->getProjectile())
				{
					if (this->plantTiles[i]->getPlant()->getProjectile()->getY() + 3 == this->enemies[j]->getY())
					{
						this->enemies[j]->modifyHitpoints(this->plantTiles[i]->getPlant()->getProjectile()->getDamage());
						this->plantTiles[i]->getPlant()->removeProjectile();
						if (this->enemies[j]->getHipoints() <= 0)
						{
							Log::getInstance().updateLog("A fost distrusa o entitate Zombie");
							score += this->enemies[j]->getPoints();
							delete this->enemies[j];
							this->enemies.erase(this->enemies.begin() + j);
						}
					}
				}
				if (j<this->enemies.size()&&this->enemies[j]->isEating())
				{
						this->enemies[j]->eat(this->plantTiles[i]->getPlant());
						if (this->plantTiles[i]->getPlant()->getResistance() <= 0)
						{
							Log::getInstance().updateLog("A fost distrusa o entitate "+ this->plantTiles[i]->getPlant()->getName());
							this->plantTiles[i]->removePlant();
							this->enemies[j]->resetEating();
						}
					
				}
				else
				{
					if (j<this->enemies.size()&&this->enemies[j]->getY() >= this->plantTiles[i]->getY() && this->enemies[j]->getY() <= this->plantTiles[i]->getY() + TILE_WIDTH)
					{
						if (this->enemies[j]->getName() == "PoleVaultingZombie" && !this->enemies[j]->isExecuted())
						{
							Log::getInstance().updateLog("Un Zombie a sarit peste o entitate de tip "+ this->plantTiles[i]->getPlant()->getName());
							this->enemies[j]->executeFunction();
						}
						else
						{
							Log::getInstance().updateLog("Un Zombie mananca dintr-o entitate "+this->plantTiles[i]->getPlant()->getName());
							this->enemies[j]->setEating();
						}
					}
					
				}
			}
		}
	}
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		if (this->enemies[i]->getY() <= REACHED_HOUSE+12)
		{
			this->life--;
			Log::getInstance().updateLog("A fost pierduta o viata de catre jucator");
			delete this->enemies[i];
			this->enemies.erase(this->enemies.begin() + i);
		}
		if (i<this->enemies.size())
		{
			this->enemies[i]->draw();
		}
	}
	this->draw();
	return score;
}
bool BattleLine::addPlant(int index, Plant* p)
{
	if (!this->plantTiles[index]->isOccupied())
	{
		this->plantTiles[index]->addPlant(p);
		return true;
	}
	return false;
}
bool BattleLine::getSuns(int x, int y)
{
	for (int i = 0; i < this->plantTiles.size(); ++i)
	{
		if (this->plantTiles[i]->pressedInside(x,y))
		{
			return this->plantTiles[i]->getSuns(x,y);
			Log::getInstance().updateLog("A fost obtinut un obiect de tip Sun");
		}
	}
	return false;
}