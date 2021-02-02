#include "PlantShop.h"
PlantShop* PlantShop::instance = nullptr;

PlantShop::PlantShop()
{
	this->begin = steady_clock::now();
	this->startX = 7;
	this->startY = 0;
	this->genPeaShooter = steady_clock::now();
	this->genSunflower = steady_clock::now();
	this->genWallNut = steady_clock::now();
	this->genCherryBomb = steady_clock::now();
	this->delayPeaShooter = 20000;
	this->delaySunflower = 15000;
	this->delayWallNut = 30000;
	this->delayCherryBomb = 50000;
	this->genSunflower = steady_clock::now(); //timpul la care se va genera un obiect 'Plant' de tip SunFlower
	this->genPeaShooter = steady_clock::now(); //timpul la care se va genera un obiect 'Plant' de tip Peashooter
	for (int i = 0; i < 5; ++i)
	{
		this->tiles.push_back(new AvatarTile(this->startX + 1 + this->tiles.size() * TILE_HEIGHT, this->startY + 1));
	}
}
PlantShop& PlantShop::getInstance()
{
	if (!PlantShop::instance)
	{
		PlantShop::instance = new PlantShop;
	}
	return *PlantShop::instance;
}
void PlantShop::draw()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->startX, this->startY) << (unsigned char)TL;
	conOut(this->startX, this->startY + TILE_WIDTH) << (unsigned char)TR;
	conOut(this->startX + 5 * TILE_HEIGHT, this->startY) << (unsigned char)BL;
	conOut(this->startX + 5 * TILE_HEIGHT, this->startY + TILE_WIDTH) << (unsigned char)BR;
	for (int i = 0; i < this->tiles.size(); ++i)
	{
		this->tiles[i]->draw();
	}
}
void PlantShop::executeFunction()
{
	srand(unsigned(time(0)));
	//TO DO:
	//spawn times for cherrybomb, wallnut and snow pea
	auto end = steady_clock::now();
		if (duration_cast<milliseconds>(end - this->genSunflower).count() > delaySunflower)
		{
			this->genSunflower = end;
			int gen = 3 + rand() % 3;
			delaySunflower = (gen * 10 + 8) * 1000;
			for (int i = 0; i < this->tiles.size(); ++i)
			{
				if (!this->tiles[i]->isOccupied())
				{
					this->tiles[i]->addAvatar(new Avatar("Sunflower", this->tiles[i]->getX(), this->tiles[i]->getY()));
					break;
				}
			}
		}
		if (duration_cast<milliseconds>(end - this->genPeaShooter).count() > delayPeaShooter)
		{
			this->genPeaShooter = end;
			int gen = 2 + rand() % 3;
			delayPeaShooter = (gen * 10 + 5) * 1000;
			for (int i = 0; i < this->tiles.size(); ++i)
			{
				if (!this->tiles[i]->isOccupied())
				{
					this->tiles[i]->addAvatar(new Avatar("PeaShooter", this->tiles[i]->getX(), this->tiles[i]->getY()));
					break;
				}
			}
		}
		if (duration_cast<milliseconds>(end - this->genWallNut).count()> delayWallNut)
		{
			this->genWallNut = end;
			int gen = 3 + rand() % 3;
			delayWallNut = (gen * 11 + 2) * 1000;
			for (int i = 0; i < this->tiles.size(); ++i)
			{
				if (!this->tiles[i]->isOccupied())
				{
					this->tiles[i]->addAvatar(new Avatar("WallNut", this->tiles[i]->getX(), this->tiles[i]->getY()));
					break;
				}
			}
		}
		if (duration_cast<milliseconds>(end - this->genCherryBomb).count() > delayCherryBomb)
		{
			this->genCherryBomb = end;
			int gen = 5 + rand() % 3;
			delayCherryBomb = (gen * 10 + 6) * 1000;
			for (int i = 0; i < this->tiles.size(); ++i)
			{
				if (!this->tiles[i]->isOccupied())
				{
					this->tiles[i]->addAvatar(new Avatar("CherryBomb", this->tiles[i]->getX(), this->tiles[i]->getY()));
					break;
				}
			}
		}
	
	this->draw();
}
int PlantShop::getAvatarIndex(vector<int>coord)
{
	if ((coord[0] >= this->startX && coord[0] <= this->startX + 5 * TILE_HEIGHT) && (coord[1] >= this->startY && coord[1] <= this->startY + TILE_WIDTH))
	{
		if (this->tiles[(coord[0]-this->startX-1) / TILE_HEIGHT]->isOccupied())
		{
			return (coord[0] - this->startX-1) / TILE_HEIGHT;
		}
	}
	return -1;
}
int PlantShop::getAvatarCost(int index)
{
	return this->tiles[index]->getAvatar()->getCost();
}
void PlantShop::removeAvatar(int index)
{
	this->tiles[index]->removeAvatar();
}