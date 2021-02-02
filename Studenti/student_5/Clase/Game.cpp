#include "Game.h"
#include <time.h>
#include "Zombie.h"
#include "Sun.h"
#include "PeaShooter.h"
#include "Pea.h"
#define Left_x 5
#define top_y 5
#define Right_x 95
#define bottom_y 41
#define box_offset_x 10
#define box_offset_y 6
#define timer_sun 8.0f
#define timer_plant 5
#define timer_zombie 15
#define sun_y 7
#define max_sun 8
#define max_plant 5
#define select_plant_offset 3
#define sunFloawerName "sunPlant"
#define peaShooterName "shooter"
#define shootTimer 8
#define zombie_types 2
#define zombie_number 5
#define level 5;
#define zombie_start_x 85
#define sun_cost 1
#define scor_pick_sun 50
#define scor_hit_zombie 70
#define scor_plant 50
#define gameOver_X 15

Game::Game(UserInterface::ConsoleOutput conOut)
{
	this->conOut = conOut;
	isSelected = false;
	drawTime = std::chrono::steady_clock::now();
	sunCounter = 0;
	zombie_counter = zombie_number;
	sunSpawnTimer = timer_sun;
	gameOver = false;
	win = false;
	outLog.open("log.log");
}


Game::~Game()
{
}

void Game::start()
{
	//linia de sus
	for (int i = Left_x; i <= Right_x; i++)
		conOut(i, top_y) << "_";
	//linia de jos
	for (int i = Left_x; i <= Right_x; i++)
		conOut(i, bottom_y) << "_";
	//linia din stanga
	for (int i = top_y + 1; i <= bottom_y; i++)
		conOut(Left_x, i) << "|";
	//linia din drepta
	for (int i = top_y + 1; i <= bottom_y; i++)
		conOut(Right_x, i) << "|";

	//linia orizontala de la zona de sori
	for (int i = Left_x + 1; i < Right_x; i++)
		conOut(i, top_y + box_offset_y) << "_";

	//linile verticale de la zona de alegere
	for (int x = Left_x; x <= Right_x; x += box_offset_x)
		for (int y = top_y + 1; y <= box_offset_x; y++)
			conOut(x, y) << "|";

	//linile orizontale de la zona de alegere
	for (int y = top_y; y <= bottom_y; y += box_offset_y) {
		for (int x = Left_x + 1; x < Right_x; x++)
			conOut(x, y) << "_";
	}

	//linia verticala de la zona de alegere
	for (int i = top_y + 1; i <= bottom_y; i++)
		conOut(Left_x + box_offset_x, i) << "|";

	conOut(6, 6) << "Suns: "<<sunCounter;
	conOut(6, 7) << "Score: " << scor;
	outLog << "a inceput jocul\n";
	
}

void Game::update(std::pair<int, int> mousePoz, bool hasDoubleClicked)
{
	srand((int)time(0));
	auto now = std::chrono::system_clock::now();
	auto now2 = std::chrono::steady_clock::now();
	auto dropDeadEntity = [&](std::vector<Entity*> &list) {
		for (auto it = list.begin(); it != list.end();) {
			if ((*it)->getGlyph().find(" ") != std::string::npos) {
				it = list.erase(it);
			}
			if (it != list.end())
				it++;
		}
		outLog << "a fost scos o entitate dintr o lista\n";
	};
	//pun planta pe arena 
	if (selectedPlant != nullptr && hasDoubleClicked) {
		selectedPlant->setX(mousePoz.first);
		int y = mousePoz.second;
		while (y % 6 != 0)
			y--;
		selectedPlant->setY(y + select_plant_offset - 1);
		conOut(selectedPlant->getX(), selectedPlant->getY()) << selectedPlant->getGlyph();
		arenaPlants.push_back(selectedPlant);
		draw.push_back(selectedPlant);
		selectedPlant = nullptr;
		outLog << "a fost pusa o planta pe arena\n";
	}
	// a dat dublu click pe un soare 
	if (hasDoubleClicked) {
		for (int i = 1; i <= max_sun; i++) {
			if (mousePoz.first > i * box_offset_x + Left_x
				&& mousePoz.first < i * box_offset_x + box_offset_x + Left_x
				&& mousePoz.second > top_y
				&& mousePoz.second < top_y + box_offset_y) {
				for (auto it = sunList.begin(); it != sunList.end();) {
					if ((*it)->getX() == i * box_offset_x + Left_x + 1) {
						conOut((*it)->getX(), (*it)->getY()) << "   ";
						sunCounter++;
						delete (*it);
						it = sunList.erase(it);
						scor += scor_pick_sun;
					}
					if (it != sunList.end())
						it++;
				}
				outLog << "a dat dublu click pe un soare\n";
			}
		}
	}
	//TO_DO: a dat dublu click pe o planta
	if (hasDoubleClicked) {
		if (selectedPlant == nullptr ) {
			for (int i = 1; i <= max_plant; i++) {
				if (mousePoz.first > Left_x
					&& mousePoz.first < box_offset_x + Left_x
					&& mousePoz.second > top_y + i * box_offset_y
					&& mousePoz.second < top_y + box_offset_y + i * box_offset_y && sunCounter >= sun_cost) {
					for (auto it = plantList.begin(); it != plantList.end();) {
						if ((*it)->getY() == i * box_offset_y + top_y + select_plant_offset) {
							std::string delGlyph = "";
							for (int j = 0; j < (*it)->getGlyph().size(); j++) {
								delGlyph += " ";
							}
							conOut((*it)->getX(), (*it)->getY()) << delGlyph;
							selectedPlant = (*it);
							it = plantList.erase(it);
						}
						if (it != plantList.end())
							it++;
					}
					scor += scor_plant;
					sunCounter -= sun_cost;
					outLog << "a dat dublu click pe o planta";
				}
			}
			
		}
	}

	//TO_DO: plantele arunca proiectilul la un anumit timp
	for (auto plant : arenaPlants) {
		std::chrono::duration<float> aux = now - plant->getTimer();
		float timer = aux.count();
		if (timer > shootTimer && plant->getGlyph() == peaShooterName) {
			Entity *pea = new Pea(plant->getGlyph().size() + plant->getX() + 1, plant->getY());
			draw.push_back(pea);
			peaList.push_back(pea);
			plant->setTimer(now);
			outLog << "o planta a aruncat un proiectil\n";
		}
		if (plant->getSpecial()) {
			sunSpawnTimer -= 0.5;
		}
	}
	//zombie se lupta cu o planta
	for (auto zom : zombieList) {
		for (auto plant : arenaPlants) {
			if (zom->getX() + zom->getMovement() < plant->getX() + plant->getGlyph().size() + 1 && zom->getY() == plant->getY()) {
				zom->interact(*plant);
				outLog << "un zombie a omorat o planta\n";
				
			}
		}
		if (zom->getX() == gameOver_X) {
			gameOver = true;
			outLog << "a pierdut jocul";
			return;
		}
	}
	//un proiectil loveste un zombie
	for (auto zom : zombieList) {
		for (auto pea : peaList) {
			if (zom->getX() + zom->getMovement() < pea->getX() + pea->getGlyph().size() + 1 && zom->getY() == pea->getY()) {
				pea->interact(*zom);
				scor += scor_hit_zombie;
				outLog << "un proiectil a lovit un zombie\n";
			}
		}
	}

	//desenarea
	if (std::chrono::duration_cast<std::chrono::milliseconds>(now2 - drawTime).count() > 500) {
		for (auto entitate = draw.begin(); entitate != draw.end();) {
			conOut((*entitate)->getX() + (*entitate)->getGlyph().size() - 1, (*entitate)->getY()) << " ";
			(*entitate)->setX((*entitate)->getX() + (*entitate)->getMovement());
			if ((*entitate)->getX() < Right_x - 1 && ((*entitate)->getX() > Left_x + box_offset_x - 1)) {
				conOut((*entitate)->getX(), (*entitate)->getY()) << (*entitate)->getGlyph();
				/*if ((*entitate)->getX() > Left_x + box_offset_x - 1 && (*entitate)->getX() < Left_x + 2 * box_offset_x - 1) {
					gameOver = true;
					outLog << "a pierdut jocul\n";
					return;
				}*/

			}
			else
				(*entitate)->setGlyph(" ");
			if ((*entitate)->getGlyph().find(" ") != std::string::npos) {
				entitate = draw.erase(entitate);
			}
			if (entitate != draw.end()) {

				entitate++;
			}

		}
		drawTime = now2;
		outLog << "s-a desenat urmatorul frame\n";
	}
	dropDeadEntity( arenaPlants);
	dropDeadEntity( zombieList);
	dropDeadEntity(peaList);
	for (auto it = draw.begin(); it != draw.end();) {
		if ((*it)->getGlyph().find(" ") != std::string::npos) {
			conOut((*it)->getX(), (*it)->getY()) << (*it)->getGlyph();
			delete(*it);
			it = draw.erase(it);
		}
		if (it != draw.end())
			it++;
	}
	if (zombieList.size() == 0 && zombie_counter == 0) {
		win = true;
		outLog << "a castigat";
		return;
	}
	conOut(12, 6) << sunCounter;
	conOut(13, 7) << scor;
}

void Game::sunSpawn(std::chrono::time_point<std::chrono::system_clock> &time)
{
	auto now = std::chrono::system_clock::now();
	std::chrono::duration<float> aux = now - time;
	float timerSpawn = aux.count();
	if (sunList.size() < max_sun) {
		if (timerSpawn >= sunSpawnTimer) {
			bool isGood;
			int pozX;
			do {
				pozX = (rand() % max_sun + 1);
				isGood = true;
				for (auto &sun : sunList) {
					if (sun->getX() == pozX * box_offset_x + Left_x + 1) {
						isGood = false;
						break;
					}
				}
			} while (!isGood);
			Entity* sun = new Sun(pozX * box_offset_x + Left_x + 1, sun_y);
			sunList.push_back(sun);
			conOut(sun->getX(), sun->getY()) << sun->getGlyph();
			//draw.push_back(sun);
			time = now;
			outLog << "s-a spawnat un soare\n";
		}
	}
	
}

void Game::plantSpawn(std::chrono::time_point<std::chrono::system_clock>& time)
{
	auto now = std::chrono::system_clock::now();
	std::chrono::duration<float> aux = now - time;
	float timerSpawn = aux.count();
	if (plantList.size() < max_plant) {
		if (timerSpawn >= timer_plant) {
			Entity *plant = nullptr;
			bool isGood;
			int pozY;
			do {
				pozY = (rand() % max_plant + 1);
				isGood = true;
				for (auto &plant : plantList) {
					if (plant->getY() == pozY * box_offset_y + top_y + select_plant_offset) {
						isGood = false;
						break;
					}
				}
			} while (!isGood);
			int select(rand() % 2 + 1);
			switch (select)
			{
			case 1:
				plant = new PeaShooter(Left_x + 2, pozY * box_offset_y + top_y + select_plant_offset, "shooter");
				break;
			case 2:
				plant = new PeaShooter(Left_x + 2, pozY * box_offset_y + top_y + select_plant_offset, "sunPlant");
				plant->setGlyph(sunFloawerName);
				break;
			default:
				break;
			}
			//draw.push_back(plant);
			conOut(plant->getX(), plant->getY()) << plant->getGlyph();
			plantList.push_back(plant);
			time = now;
			outLog << "s-a spawnat o planta\n";
		}
	}
}

void Game::zombieSpawn(std::chrono::time_point<std::chrono::system_clock>& time)
{
	auto now = std::chrono::system_clock::now();
	std::chrono::duration<float> aux = now - time;
	float timerSpawn = aux.count();
	if (zombieList.size() <= zombie_number) {
		if (timerSpawn >= timer_zombie) {
			zombie_counter--;
			Entity* zombie;
			int pozY = rand() % level;
			pozY++;
			pozY = pozY * box_offset_y + top_y + select_plant_offset;
			int select(rand() % zombie_types + 1);
			switch (select)
			{
			case 1:
				zombie = new Zombie(zombie_start_x, pozY, 2);
				break;
			case 2:
				zombie = new Zombie(zombie_start_x, pozY, 4);
				break;
			default:
				break;
			}
			draw.push_back(zombie);
			zombieList.push_back(zombie);
			time = now;
			outLog << "s-a spawnat un zombie\n";
		}

	}
}

bool Game::getGameOver()
{
	return gameOver;
}

bool Game::getWin()
{
	return win;
}

int Game::getScor()
{
	return scor;
}

void Game::gameClear()
{
	for (int y = top_y; y <= bottom_y; y++)
		for (int x = Left_x; x <= Right_x; x++)
			conOut(x, y) << " ";
}

