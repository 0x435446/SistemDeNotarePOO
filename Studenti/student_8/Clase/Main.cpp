
#include <time.h>
#include <chrono>
#include "Logger.h"
#include "Map.h"
#include <vector>
#include "Sun.h"
#include "PeaShooter.h"
#include <iostream>
#include <stdio.h>
#include "Zombie.h"
#include "Sunflower.h"
#include <utility>
#include <random>
#include "Proiectil.h"
#include "Users.h"
#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5
#define PI 3.14

#pragma warning(disable:4996)
using namespace std::chrono;

bool checkCollisionMP(int x1, int y1, int x2, int y2)
{
	if (y1 == y2 && x2 == x1-1)
		return true;

	return false;
}
bool checkCollisionPM(int x1, int y1, int x2, int y2)
{
	if (y1 == y2 && x2+1 == x1)
		return true;

	return false;
}
void Game()
{
	int score = 0;
	int money = 200;
	int interval = 10;
	unsigned int level=1;
	int rando[5] = {12,15,18,21,24 };
	std::random_device rd; 
	std::mt19937 eng(rd());
	srand((unsigned int)time(NULL));
	Log *logger = logger->getInstance();
	time_t when = time(NULL);
	logger->setInfo("S-a creat/ logat utilizatorul ! ", (ctime)(&when));
	logger->writeLog();
	Users::takeCredentials();
	system("cls");
	cout << "Alegeti nivelul 1  2  3 :";
	cin >> level;
	try
	{
		if (level > 3 || level == 0)
			throw 100;

	}
	catch (int y)
	{
		if (y = 100)
		{
			cout << "Ati ales un level inexistent , se alege nivelul 1 !";
			Sleep(1000);
			level = 1;
		}
		

	}
	system("cls");
	std::uniform_int_distribution<> distr(0, level * 2-2);
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	time_point<steady_clock> timerr = steady_clock::now();
	time_point<steady_clock> timerrr = steady_clock::now();
	Map *map = map->getInstance(level);
	logger->setInfo("S-a creat mapa ! ", (ctime)(&when));
	logger->writeLog();
	Sun *vec = new Sun[7];
	vector<Sunflower> SunflowerVector;
	vector<PeaShooter> PeaShooterVector;
	vector<Zombie> ZombieVector;
	for (int i = 0; i < 7; ++i)
	{
		vec[i] = Sun(i);
	}
	while (true)
	{
		string action = conIn.getUserActions();
		conOut(3, 2) << action;
		for (int i = 0; i < 7; ++i)
			money = money + vec[i].cursor(action);
		if(45 * level - duration_cast<seconds>(steady_clock::now() - timerrr).count()>=0)
		conOut(50, 30) <<"Time remaining : "<<45*level - duration_cast<seconds>(steady_clock::now() - timerrr).count() << " ";
		if (duration_cast<seconds>(steady_clock::now() - timerrr).count() < 45*level)
		{
			if (duration_cast<seconds>(steady_clock::now() - timerr).count() > 5)
			{
				timerr = steady_clock::now();
				ZombieVector.push_back(Zombie(115, rando[distr(eng)]));
			
			}
		
		}
		else
		{
			if (ZombieVector.empty())
			{
				conOut(70, 6) << "Ai castigat !!!";
				return;
			}
		}
		PeaShooter::getCoordXY(action, PeaShooterVector, money);
		Sun::verifAfisare(vec, interval);
		if(SunflowerVector.size()!=0 && SunflowerVector.size()<=7)
		   interval = 3 + 7-SunflowerVector.size();
		conOut(50, 29) <<"Sun aparition interval : "<<interval<<" ";
		conOut(50, 28) << "Zombies to kill : " <<ZombieVector.size()<< " ";
		Sunflower::getCoordXY(action, SunflowerVector, money);
	
		if(SunflowerVector.size()!=0 && !ZombieVector.empty())
			for (int i = 0; i < SunflowerVector.size(); ++i)
					for (int j = 0; j < ZombieVector.size(); ++j)
						if (checkCollisionMP(ZombieVector[j].getX(), ZombieVector[j].getY(), SunflowerVector[i].getX(), SunflowerVector[i].getY()) == true)
						{
							ZombieVector[j].setSpeed(10000);
							SunflowerVector[i].FightWith(ZombieVector[j]);
							if (SunflowerVector[i].getViata() < 1)
							{
								ZombieVector[j].setSpeed(1);
								logger->setInfo("A murit un sunflower ! ", (ctime)(&when));
								logger->writeLog();
								SunflowerVector.erase(SunflowerVector.begin()+i); 
								
							}
			            }
	
		if (PeaShooterVector.size()!=0)
		{
			for (auto it = PeaShooterVector.begin(); it != PeaShooterVector.end(); ++it)
			{
				(*it).setProiectile();
				(*it).doProiectilMove();
				for (int i = 0; i < PeaShooterVector.size(); ++i)
					if (PeaShooterVector[i].verifProiectile() && ZombieVector.size() != 0)
						for (int j = 0; j < ZombieVector.size(); ++j)
							if (checkCollisionPM(ZombieVector[j].getX(), ZombieVector[j].getY(), PeaShooterVector[i].getFirstProiectilX(), PeaShooterVector[i].getFirstProiectilY()) == true)
							{
							
								ZombieVector[j].FightWith(PeaShooterVector[i].getFirstProiectil());
								if (PeaShooterVector[i].verifProiectile())
									PeaShooterVector[i].destroyFirstProiectil(PeaShooterVector[i].ProiectilVector);
								
							}

				for (int k = 0; k < PeaShooterVector.size(); ++k)
				{
					if (ZombieVector.size() != 0)
						for (int j = 0; j < ZombieVector.size(); ++j)
							if (checkCollisionMP(PeaShooterVector[k].getX(), PeaShooterVector[k].getY(), ZombieVector[j].getX(), ZombieVector[j].getY()) == true)
							{
								
								ZombieVector[j].setSpeed(10000);
								PeaShooterVector[k].FightWith(ZombieVector[j]);
								ZombieVector[j].FightWith(PeaShooterVector[k]);
								if (PeaShooterVector[k].getViata() < 1)
								{
							
									conOut(PeaShooterVector[k].getX(), PeaShooterVector[k].getY()) << " ";
									logger->setInfo("A murit un peashooter  ! ", (ctime)(&when));
									logger->writeLog();
									PeaShooterVector.erase(PeaShooterVector.begin() + k);

								}
							}
				}

			}
		}
		if (ZombieVector.size() != 0)
			for (int i = 0; i < ZombieVector.size(); ++i)
				if (ZombieVector[i].doZombieMove())
				{
				}
				else
				{
					logger->setInfo("A murit un zombie ! ", (ctime)(&when));
					logger->writeLog();
					ZombieVector.erase(ZombieVector.begin() + i);
					score = score + 20;

				}



		conOut(57, 9) << money << " ";
		conOut(57, 7) << score;
	

		for (int i = 0; i < ZombieVector.size(); ++i)
			if (ZombieVector[i].getX() <= 60)
			{
				conOut(70, 6) << "Joc pierdut !";
				return ;

			}
	}

	
}

int main(void)
{

	
	Game();

	return 0;
}