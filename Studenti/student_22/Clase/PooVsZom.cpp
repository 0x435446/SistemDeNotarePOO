#include "PooVsZom.h"
#define sprite_size 10
#define sprite_offset 5
#define fire_rate 4
#define BG_COLOUR 0x0000
#define PIXEL_SOLID 0x2588
#define moving_speed 3
#define special_sauce 2
#define zombie_attack_speed 2
#define max_sun 8
#define sun_pozY 0
#define sun_time 5
#define pick_timer 5
#define zombie_spawn_time 15
#define plant_range 5
#define max_pick 5
#define garbage 150
#define sunFlowe_reduction 0.2f
#define baseZombieNumber 2
#define zombie_range 3
#define default_zombie_x 80
#define level1 1
#define level2 2
#define level3 3
#define superZombieSpec 1
PooVsZom::PooVsZom(int level ) 
{
	this->level = level;
	missileCount = 0;
	sunTime = sun_time;
	sunTimer = std::chrono::system_clock::now();
	pickTimer = std::chrono::system_clock::now();
	scorTimer = std::chrono::system_clock::now();
	zombieTimer = std::chrono::system_clock::now();
	isSelected = false;
	scor = 0;
	soareCount = 0;
	frameScor = 0;
	zombieCounter = level * baseZombieNumber + superZombieSpec;
	gameOver = false;
	win = false;
	isSuper = true;
}

PooVsZom::~PooVsZom()
{
	
}

bool sort(std::pair < Plant*, std::chrono::time_point<std::chrono::system_clock>> elm1,
	std::pair < Plant*, std::chrono::time_point<std::chrono::system_clock>> elm2) {
	if (elm1.first->getPozY() != elm2.first->getPozY())
		return elm1.first->getPozY() < elm2.first->getPozY();
	else
		return elm1.first->getPozX() < elm2.first->getPozX();
}


bool PooVsZom::onUserCreate()
{
	outFile << screenWidth << std::endl;
	outFile.open("debug.log");
	

	Entity *xTile = new Entity();
	Entity *yTile = new Entity();
	xTile->sprite.loadSprite("x_tile.spr");
	yTile->sprite.loadSprite("y_tile.spr");
	for(int i = 1; i < 9; i++)
		drawEntity(i*sprite_size, 0, xTile);
	for (int i = 1; i < 6; i++)
		drawEntity(1, i*sprite_size, yTile);

	DrawString(1, 1, std::string("Scor:"));
	DrawString(1, 2, std::string("Suns:"));
	return true;
}

bool PooVsZom::onUserUpdate(float specialTime)
{
	
	auto trim = [&](int &x, int &y) {
		while (x % 10 != 0)
			x--;
		while (y % 10 != 0)
			y--;
	};
	
	try {
		if (isFocused()) {
			DrawString(7, 1, std::to_string(scor));
			DrawString(6, 2, std::to_string(soareCount));
			onlyonce = true;
			srand((int)time(0));
			auto nowTime = std::chrono::system_clock::now();
			std::chrono::duration<float> time;
			time = nowTime - scorTimer;
			timer = time.count();
			if (timer > 1) {
				scor++;
				scorTimer = nowTime;
			}
			time = nowTime - pickTimer;
			timer = time.count();
			//dispunearea de plante pe zona de alegere
			if (timer > pick_timer) {
				Plant *pickPlant = nullptr;
				int randPlant = rand() % plant_range + 1;
				switch (randPlant) {
				case 1:
					//planta de atack normala
					pickPlant = new Plant(0, 0);
					pickPlant->sprite.loadSprite("plant.spr");
					break;
				case 2:
					//sun flower
					pickPlant = new SunFlower(0, 0);
					pickPlant->sprite.loadSprite("sun_flower.spr");
					break;
				case 3:
					//wall-nut
					pickPlant = new WallNut(0, 0);
					pickPlant->sprite.loadSprite("wall_nut.spr");
					break;
				case 4:
					//cherry-bomb
					pickPlant = new CherryBomb(0, 0);
					pickPlant->sprite.loadSprite("cherry_bomb.spr");
					break;
				case 5:
					//snow plant
					pickPlant = new SnowPlant(0, 0);
					pickPlant->sprite.loadSprite("snow_plant.spr");
				}
				if (pickPlantList.size() < max_pick) {

					bool isGood; 
					int pozY;
					int random;
					do {
						random = (rand() % max_pick + 1);
						pozY = random * sprite_size;
						isGood = true;
						for (auto auxPlant : pickPlantList) {
							if (auxPlant->getPozY() == pozY ) {
								pickPlant->setPozY(pozY);
								isGood = false;
								break;
							}
						}
					} while (!isGood);

					pickPlant->setPozY(pozY);
					pickPlantList.push_back(pickPlant);
					drawEntity(pickPlant->getPozX(), pickPlant->getPozY(), pickPlant);
				}
				else {
					delete pickPlant;
				}
				pickTimer = nowTime;
			}
			
			//verific daca a apasat dublu click pe un soare sau pe o planta pe care sa o aleaga
			if (hasDoubledClicked) {
				if (onlyonce) {
					for (auto sun = sunList.begin(); sun != sunList.end();) {
						int posX((*sun)->getPozX());
						int posY((*sun)->getPozY());
						if ((mousePosX >= posX && mousePosX <= posX + sprite_size)
							&& (mousePosY >= posY && mousePosY <= posY + sprite_size)) {
							outFile << "a apasat pe un soare" << "\n";
							cleaningList.push_back({ (*sun)->getPozX(), (*sun)->getPozY() });
							sun = sunList.erase(sun);
							onlyonce = false;
							soareCount++;
							scor += 20;
						}
						else if (sun != sunList.end())
							sun++;
					}
				}
				
				if (!isSelected && onlyonce && soareCount >= 1) {
					for (auto pick = pickPlantList.begin(); pick != pickPlantList.end();) {
						if (mousePosY >= (*pick)->getPozY()
							&& mousePosY <= (*pick)->getPozY() + sprite_size
							&& mousePosX >= (*pick)->getPozX()
							&& mousePosX <= (*pick)->getPozX() + sprite_size) {
							cleaningList.push_back({ (*pick)->getPozX() ,(*pick)->getPozY() });
							pickedPlant = (*pick);
							pick = pickPlantList.erase(pick);
							isSelected = true;
							onlyonce = false;
							soareCount--;
						}
						else if (pick != pickPlantList.end())
							++pick;
					}
				}

				if (onlyonce && isSelected && (mousePosX > sprite_size && mousePosY > sprite_size)) {
					trim(mousePosX, mousePosY);
					pickedPlant->setPozX((int)mousePosX);
					pickedPlant->setPozY((int)mousePosY);
					fightingPlants.push_back({ pickedPlant, std::chrono::system_clock::now() });
					drawEntity(pickedPlant->getPozX(), pickedPlant->getPozY(), pickedPlant);
					isSelected = false;
					onlyonce = false;
					scor += 50;
					//sterg planta aleasa din lista de plante pe care le pot alege
					for (auto delPlant = pickPlantList.begin(); delPlant != pickPlantList.end();) {
						if ((*delPlant) == pickedPlant) {
							delPlant = pickPlantList.erase(delPlant);
						}
						else if (delPlant != pickPlantList.end())
							delPlant++;
					}
				}
				
				
			}

			//partea pentru generarea soarelui
			time = nowTime - sunTimer;
			timer = time.count();
			if (timer >= sunTime) {
				if (sunList.size() < max_sun) {
					bool isGood;
					int sun_pozX;
					int random;
					do {
						isGood = true;
						random = ((int)rand() % 8 + 1);
						sun_pozX = random * sprite_size;
						for (auto &oldSun : sunList) {
							if (sun_pozX == oldSun->getPozX()) {
								isGood = false;
								break;
							}
						}
					} while (!isGood);

					Entity* sun = new Entity(sun_pozX , sun_pozY, false, 0);
					sun->sprite.loadSprite("sun.spr");
					sunList.push_back(sun);
					drawEntity(sun->getPozX(), sun->getPozY(), sun);
				}
				sunTimer = nowTime;
			}

			//partea pentru generarea zombie
			time = nowTime - zombieTimer;
			timer = time.count();
			if (timer >= zombie_spawn_time && zombieCounter >= 0) {
				zombieCounter--;
				Zombie *zombie = nullptr;
				int randZombie = rand() % zombie_range + 1;
				int ram;
				int pozY;
				bool canItBe = rand() % 1;

				switch (level) {
				case level1:
					pozY = 3 * sprite_size;
					break;
				case level2:
					ram = rand() % lvl2YPos.size() + 1;
					pozY = lvl2YPos[ram - 1] * sprite_size;
					break;
				case level3:
					ram = rand() % max_pick + 1;
					pozY = ram * sprite_size;
					break;
				}
				if (zombieCounter == 0) {
					zombie = new SuperZombie(default_zombie_x, pozY, true);
					zombie->sprite.loadSprite("super_zombie.spr");
				}
				else {
					switch (randZombie)
					{
					case 1:
						zombie = new Zombie(default_zombie_x, pozY, true);
						zombie->sprite.loadSprite("zombie.spr");
						break;
					case 2:
						zombie = new BucketHeadZombie(default_zombie_x, pozY, true);
						zombie->sprite.loadSprite("buckethead_zombie.spr");
						break;
					case 3:
						zombie = new PoleVaultingZombie(default_zombie_x, pozY, true);
						zombie->sprite.loadSprite("poleVaulting_zombie.spr");
						break;
					default:
						break;
					}
				}

				zombieList.push_back(zombie);
				drawList.push_back(zombie);
				zombieTimer = nowTime;
			}


			auto prePlant = fightingPlants.begin();
			//verific daca un zombie s-a apropiat de o planta, daca s-a apropiat il mut in fightingZombies
			for (auto plant = fightingPlants.begin(); plant != fightingPlants.end(); plant++) {
				for (auto zombie = zombieList.begin(); zombie != zombieList.end(); ) {
					if ((*zombie)->getPozX() > (*plant).first->getPozX()
						&&(*zombie)->getPozX() - sprite_size - special_sauce < (*plant).first->getPozX() 
						&& (*zombie)->getPozY() == (*plant).first->getPozY()) {
						//caz special pt zombie care pot sa sara peste plante
						if ((*zombie)->getCanJump()) {
							//cazul in care nu poate sa sara peste doua plante
							if ((*prePlant).first->getPozX() == (*plant).first->getPozX() - sprite_size
								&& (*prePlant).first->getPozY() == (*plant).first->getPozY()) {
								fightZombies.push_back(std::make_tuple((*zombie), nowTime, (*plant).first));
								(*zombie)->setIsMoving(false);
								zombie = zombieList.erase(zombie);
							}
							else {
								(*zombie)->jump((*plant).first, sprite_size);
								if (zombie != zombieList.end())
									zombie++;
							}
						}
						else {
							fightZombies.push_back(std::make_tuple((*zombie), nowTime, (*plant).first));
							(*zombie)->setIsMoving(false);
							zombie = zombieList.erase(zombie);
						}

					}
					else if(zombie != zombieList.end())
						zombie++;
				}
				prePlant = plant;
			}
		
			//verific daca un zombie ar trb lovit de un proiectil sau un proiectil trece printr o planta
			for (auto mis = missiles.begin(); mis != missiles.end();) {
				auto movement = (*mis)->getPozX() +
					(moving_speed * specialTime * (*mis)->getMovement() * (*mis)->getIsMoving());
				for (auto plant = fightingPlants.begin(); plant != fightingPlants.end(); plant++) {
					if (movement + sprite_size >= (*plant).first->getPozX() &&
						movement <= (*plant).first->getPozX() + (sprite_size) && (*mis)->getPozY() == (*plant).first->getPozY()) {
						(*mis)->setPozX((*plant).first->getPozX() + (sprite_size + special_sauce));
						//redrawPlantList.push_back((*plant).first);
					}
				}
				for (auto zom = zombieList.begin(); zom != zombieList.end();) {
					if ((*mis)->getPozX() + (sprite_size - special_sauce) >= (*zom)->getPozX() && (*mis)->getPozY() == (*zom)->getPozY()) {
						(*zom)->interact(&(*mis));
						mis = missiles.erase(mis);
						if ((*zom)->getIsDead())
							zom = zombieList.erase(zom);
					}
					if (zom != zombieList.end())
						zom++;
				}
				for (auto zom = fightZombies.begin(); zom != fightZombies.end();) {
					if (mis != missiles.end()) {
						if ((*mis)->getPozX() >= std::get<0>(*zom)->getPozX() && (*mis)->getPozY() == std::get<0>(*zom)->getPozY()) {
							std::get<0>(*zom)->interact(&(*mis));
							mis = missiles.erase(mis);
							if (std::get<0>(*zom)->getIsDead())
								zom = fightZombies.erase(zom);
						}
					}
					if (zom != fightZombies.end())
						zom++;
				}
				if (mis != missiles.end())
					++mis;
			}

			//verific daca e timpul ca un zombie trb sa atace o planta
			for (auto fightZombie = fightZombies.begin(); fightZombie != fightZombies.end();) {
				std::chrono::duration<float> time = nowTime - std::get<1>(*fightZombie);
				//outFile << "zombie ul ar trb sa se miste:" << std::get<0>(*fightZombie)->getIsMoving() << "\n";
				float timer = time.count();
				if (timer > zombie_attack_speed) {
					std::get<1>(*fightZombie) = nowTime;
					std::get<0>(*fightZombie)->interact(&(std::get<2>(*fightZombie)));
					outFile << "wall are:" << (std::get<2>(*fightZombie))->getHealth() << "\n";
					if (!(std::get<0>(*fightZombie)->getIsDead()) && std::get<2>(*fightZombie)->getIsDead()) {
						zombieList.push_back(std::get<0>(*fightZombie));
					}
				}
				if (std::get<0>(*fightZombie)->getIsMoving() == 1) {
					fightZombie = fightZombies.erase(fightZombie);
				}
				else if (std::get<0>(*fightZombie)->getIsDead()) {
					fightZombie = fightZombies.erase(fightZombie);
				}
				else if (fightZombie < fightZombies.end())
					++fightZombie;

			}

			//sortez plantele ca sa mi fie mai usor sa mi dau seama cate plante sunt consecutive
			std::sort(fightingPlants.begin(), fightingPlants.end(), sort);

			//verific daca e timpul ca una dintre plante trebuie sa atace verific si daca a murit vreo planta
			for (auto plant = fightingPlants.begin(); plant != fightingPlants.end();) {
				if ((*plant).first->getHealth() <= 0) {
					cleaningList.push_back({ (*plant).first->getPozX(),(*plant).first->getPozY() });
					delete (*plant).first;
					plant = fightingPlants.erase(plant);
				}
				else {
					std::chrono::duration<float> time = nowTime - (*plant).second;
					timer = time.count();
					//verific cate plante sunt in fata plantei care arunca proiectilul
					int plantCounter = 1;
					for (auto plant2 = plant + 1; plant2 != fightingPlants.end(); plant2++) {
						if ((*plant).first->getPozY() == (*plant2).first->getPozY()
							&& (*plant).first->getPozX() == (*plant2).first->getPozX() - sprite_size * plantCounter) {
							plantCounter++;
						}
					}
					if (timer > fire_rate && (*plant).first->getAttackingType() == "normal") {
						//cand o planta trebuie sa atace introduc un proiectil nou in lista de desenare
						Missile* missile = new Missile((*plant).first->getPozX() + (sprite_size * plantCounter),
							(*plant).first->getPozY(), true, 1);
						missile->sprite.loadSprite("basicMissile.spr");
						missiles.push_back(missile);
						drawList.push_back(missile);
						(*plant).second = nowTime;
					}
					if (timer > fire_rate && (*plant).first->getAttackingType() == "snow") {
						Missile* missile = new FrozenMissile((*plant).first->getPozX() + (sprite_size * plantCounter),
							(*plant).first->getPozY(), true, 1);
						missile->sprite.loadSprite("frozen_missile.spr");
						missiles.push_back(missile);
						drawList.push_back(missile);
						(*plant).second = nowTime;
					}
					//can este pusa un sun-flower scad timer ul de la soare
					if ((*plant).first->getAttackingType() == "sun") {
						sunTime -= sunFlowe_reduction;
					}
					++plant;
				}
				//(*plant).first->special(this);
			}

			//redesenez portiunile care trb "curatate"
			for (auto &elem2 : cleaningList) {
				fill(elem2.first, elem2.second, elem2.first + sprite_size, elem2.second + sprite_size,
					PIXEL_SOLID, BG_COLOUR);
			}
			cleaningList.clear();

			//bucata de cod care se ocupa cu tot ce tine de desenare
			for (auto& elem : drawList) {
				//prima ora sterg ce era inainte
				fill(elem->getLastPozX(), elem->getLastPozY(),
					elem->getLastPozX() + sprite_size,
					elem->getLastPozY() + sprite_size, PIXEL_SOLID, BG_COLOUR);
				//sterg tot ce nu mai trb sa fie pe ecran

				//desenez
				drawEntity(elem->getPozX(), elem->getPozY(), elem);
				//verific daca un obiect a iesit de pe consola
				auto movement = elem->getPozX() + (moving_speed * specialTime * elem->getMovement() * elem->getIsMoving()*elem->getMovingSpeed());
				if (movement < screenWidth) {
					elem->setPozX(movement);
				}
				//else if(movement <= 0) {
				//	//TO_DO GAME_OVER
				//}
				else {
					outFile << "nu se mai misca";
					elem->setIsMoving(false);
					elem->setIsDead(true);
				}
				//outFile << "passed drawing" << std::endl;
			}

			//sterg zombii care au murit si verific daca e gameOver
			for (auto it = zombieList.begin(); it != zombieList.end();) {
				if ((*it)->getIsDead()) {
					cleaningList.push_back({ (*it)->getPozX(), (*it)->getPozY() });
					it = zombieList.erase(it);
					outFile << "passed zombie cleaning" << std::endl;
				}
				else {
					if ((*it)->getPozX() < sprite_size + special_sauce) {
						outFile << "ai pierdut";
						gameOver = true;
						return false;
					}
					if (it != zombieList.end())
						it++;
				}
				
			}

			//sterg obiectele care nu mai trebuie desenate
			for (auto it = drawList.begin(); it != drawList.end();) {
				if ((*it)->getIsDead()) {
					
					cleaningList.push_back({ (*it)->getPozX(), (*it)->getPozY() });
					outFile << "sterg" << (*it)->getTag() << "\n";
					delete *it;
					it = drawList.erase(it);
					outFile << "passed removing from drawList" << std::endl;
				}
				else {
					if (it != drawList.end())
						++it;
				}
			}

			if (zombieList.size() == 0 && zombieCounter < 0) {
				win = true;
				return false;
			}
		}
	}
	catch (std:: exception &e) {
		outFile << e.what()<<"\n";
	}
	return true;
}

void PooVsZom::setSunTime(float suntTime)
{
	this->sunTime = sunTime;
}

float PooVsZom::getSunTime()
{
	return this->sunTime;
}

void PooVsZom::setLevel(int level)
{
	this->level = level;
}

bool PooVsZom::getWin()
{
	return this->win;
}

int PooVsZom::getScor()
{
	return scor;
}
