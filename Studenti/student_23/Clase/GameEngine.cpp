#include "GameEngine.h"

#define SUNFLOWER_COST 50
#define PEASHOOTER_COST 100
#define WALLNUT_COST 150
#define TIME_SUNS 2

GameEngine* GameEngine::instance = NULL;
int GameEngine::level = 0;
int GameEngine::money = 0;
int GameEngine::nrSuns = 0;
vector<Sunflower> GameEngine::sunflowers;
vector<PeaShooter> GameEngine::peashooters;
vector<WallNut> GameEngine::wallnuts;
vector<NormalZombie> GameEngine::zombies;
vector<BucketHead> GameEngine::bucketheads;
vector<Projectile> GameEngine::proiectile;

GameEngine& GameEngine::getInstance()
{
	if (!GameEngine::instance) {
		GameEngine::instance = new GameEngine();
	}
	return *GameEngine::instance;
}

void GameEngine::destroyInstance()
{
	if (GameEngine::instance) {
		delete GameEngine::instance;
		GameEngine::instance = nullptr;
	}
}


GameEngine::GameEngine()
{

}

void GameEngine::PlantVsZombies()
{

	while (1) {
		char choice;
		std::cout << "Doriti sa creati un player nou?(y/n):";
		std::cin >> choice;
		std::string buffer;

		if (choice == 'y') {
			std::cout << "Inserati numele:";
			std::cin >> buffer;
			Players::setName(buffer);
			std::cout << "Inserati parola:";
			std::cin >> buffer;
			Players::setPassword(buffer);
			Players::setScore(0);
			Players::addPlayer();

			break;
		}
		else if (choice == 'n') {
			int corect = -2;

			do
			{
				std::cout << "Inserati numele contului:";
				std::cin >> buffer;
				Players::setName(buffer);
				std::cout << "Inserati parola contului:";
				std::cin >> buffer;
				Players::setPassword(buffer);

				corect = Players::checkPlayer();
				if (corect == 0) {
					std::cout << "Parola inserata gresit, mai incercati.\n";
				}
				if (corect == -1) {
					std::cout << "Numele nu a fost gasit, mai incercati.\n";
				}
			} while (corect <= 0);
			break;
		}
		cout << "Caracter inserat gresit, va rog sa mai incercati.\n";

	}

	system("cls");
	Map instance;
	instance.drawTiles(3, 0);

	auto begin = std::chrono::steady_clock::now();
	auto begin_projectile1 = begin;
	auto begin_projectile2 = begin;
	srand(time(NULL));

	int nrClicks = 0;
	int caz;
	int X, Y;
	int loaded = 0;
	int line_new_zombie = 0;
	int line_new_plant = 0;
	int counter = 0;
	float time_new_sunshine = TIME_SUNS;
	money = 100;
	instance.updateMoney(money);

	while (true) {
		time_new_sunshine = TIME_SUNS - (sunflowers.size() / 10.0);
		if (time_new_sunshine <= 0)
			time_new_sunshine = 0.1;
		auto end = std::chrono::steady_clock::now();
		auto end_projectile1 = end;
		auto end_projectile2 = end;
		DoubleClick::getInstance();
		instance.userAction();
		if (std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() >= time_new_sunshine && nrSuns < 9) {
			begin = end;
			nrSuns++;
			instance.drawSunshine(nrSuns);
		}


		//this code adds zombies at random intervals
		if (rand() % ((zombies.size() + 1) * 10000 + (bucketheads.size() + 1) * 5000) == 10) {
			line_new_zombie = ((rand() % 5) + 1) * 6;
			if (zombies.size() >= 5 * (bucketheads.size() + 1)) {

				instance.drawZombie(150, line_new_zombie, 'b');
				bucketheads.push_back(BucketHead(150, line_new_zombie));

			}
			else {
				instance.drawZombie(150, line_new_zombie, 'z');
				zombies.push_back(NormalZombie(150, line_new_zombie));
			}
		}

		//this code adds flowers using user input
		if (DoubleClick::getNrClicks() > nrClicks) {
			DoubleClick::getCoords1(X, Y);
			caz = instance.checkCoords(X, Y);
			switch (caz)
			{
			case 1:
				if (nrSuns) {
					instance.tester("                ");
					instance.tester("Soare");
					instance.deleteSunshine(nrSuns);

					money += 25;
					nrSuns--;
					instance.updateMoney(money);
				}
				DoubleClick::setNrClicks(0);
				nrClicks = -1;

				break;

			case 2:
				instance.tester("                ");
				if (money >= SUNFLOWER_COST) {
					loaded = 1;
					instance.tester("Sunflower");
				}
				else {
					instance.tester("Not enough suns");
				}
				DoubleClick::setNrClicks(0);
				nrClicks = -1;
				break;

			case 3:
				instance.tester("                ");
				if (money >= PEASHOOTER_COST) {
					instance.tester("PeaShooter");
					loaded = 2;
				}
				else {
					instance.tester("Not enough suns");
				}
				DoubleClick::setNrClicks(0);
				nrClicks = -1;
				break;

			case 4:
				instance.tester("                ");
				if (money >= WALLNUT_COST) {

					instance.tester("Wallnut");
					loaded = 3;
				}
				else {
					instance.tester("Not enough suns");
				}
				DoubleClick::setNrClicks(0);
				nrClicks = -1;
				break;

			case 5:
				instance.tester("                ");
				instance.tester("Field");
				switch (loaded)
				{
				case 1:
					if (line_new_plant=instance.drawPlant(X, Y, 's')) {
						sunflowers.push_back(Sunflower(X, line_new_plant));
						money -= SUNFLOWER_COST;
						instance.updateMoney(money);
					}
				case 2:
					if (line_new_plant=instance.drawPlant(X, Y, 'p')) {
						peashooters.push_back(PeaShooter(X, line_new_plant));
						money -= PEASHOOTER_COST;
						instance.updateMoney(money);
					}
				case 3:
					if (line_new_plant=instance.drawPlant(X, Y, 'w')) {
						wallnuts.push_back(WallNut(X, line_new_plant));
						money -= WALLNUT_COST;
						instance.updateMoney(money);
					}
				default:
					break;
				}

				DoubleClick::setNrClicks(0);
				nrClicks = -1;
				loaded = 0;
				break;

			default:
				instance.tester("                ");
				DoubleClick::setNrClicks(0);
				nrClicks = -1;
				loaded = 0;
				break;
			}
			nrClicks++;
		}

		//code that updates projectiles
		int X_proiectil, Y_proiectil;
		if (std::chrono::duration_cast<std::chrono::seconds>(end_projectile1 - begin_projectile1).count() >= 4) {
			begin_projectile1 = end_projectile1;

			//creaza noi proiectile
			if (peashooters.size() > 0) {
				for (auto it_peashooter = peashooters.begin(); it_peashooter != peashooters.end(); it_peashooter++) {
					proiectile.push_back(Projectile(it_peashooter->getX(), it_peashooter->getY(), it_peashooter->getDamage(), it_peashooter->getSpecialEffect(), '>'));
				}
			}
		}
		if (std::chrono::duration_cast<std::chrono::seconds>(end_projectile2 - begin_projectile2).count() >= 2) {
			begin_projectile2 = end_projectile2;
			//muta proiectile deja create
			if (proiectile.size() > 0) {
				for (auto it_proiectile = proiectile.begin(); it_proiectile != proiectile.end(); it_proiectile++) {
					it_proiectile->updateX();
					it_proiectile->getCoords(X_proiectil, Y_proiectil);


					instance.drawProjectile(X_proiectil, Y_proiectil, '>');
				}
			}

			//coliziune cu zombie
			counter = -1;
			for (auto it_proiectile = proiectile.begin(); it_proiectile != proiectile.end(); it_proiectile++) {
				counter++;
				for (auto it_zombie = zombies.begin(); it_zombie != zombies.end(); it_zombie++) {

					it_proiectile->getCoords(X_proiectil, Y_proiectil);
					if (X_proiectil == it_zombie->getX() && Y_proiectil == it_zombie->getY()) {
						it_zombie->setHealth(it_zombie->getHealth() - it_proiectile->getDamage());
						proiectile.erase(proiectile.begin() + counter);
						if (proiectile.size()) {
							it_proiectile = proiectile.begin();

						}
						else {
							counter = -1;
							break;
						}
						
					}
				}
				for (auto it_buckethead = bucketheads.begin(); it_buckethead != bucketheads.end(); it_buckethead++) {
					if (X_proiectil == it_buckethead->getX() && Y_proiectil == it_buckethead->getY()) {
						it_buckethead->setHealth(it_buckethead->getHealth() - it_proiectile->getDamage());
						proiectile.erase(it_proiectile + counter + counter);
						if (proiectile.size()) {
							it_proiectile = proiectile.begin();

						}
						else {
							counter = -1;
							break;
						}
					}
				}

			}
			for (auto it_proiectile = proiectile.begin(); it_proiectile != proiectile.end(); it_proiectile++) {
				instance.drawProjectile(X_proiectil, Y_proiectil, '>');
			}

			counter = -1;
			//Code that updates zombies
			if (zombies.size() > 0) {
				counter++;
				for (auto it_zombie = zombies.begin(); it_zombie != zombies.end(); it_zombie++) {
					if (it_zombie->getHealth() < 0) {
						zombies.erase(it_zombie + counter);
						it_zombie = zombies.begin();
						counter = -1;
					}
					else {
						it_zombie->setCoords(it_zombie->getX() - 1, it_zombie->getY());

						instance.drawZombie(it_zombie->getX(), it_zombie->getY(), 'z');
						if (it_zombie->getX() == 15) {
							instance.clearScreen();
							instance.gameOver();
						}

					}
				}
			}
			if (bucketheads.size() > 0) {
				for (auto it_buckethead = bucketheads.begin(); it_buckethead != bucketheads.end(); it_buckethead++) {
					if (it_buckethead->getHealth() < 0) {
						bucketheads.erase(it_buckethead + counter);
						it_buckethead = bucketheads.begin();
						counter = -1;
					}
					else {
						it_buckethead->setCoords(it_buckethead->getX() - 1, it_buckethead->getY());

						instance.drawZombie(it_buckethead->getX(), it_buckethead->getY(), 'b');
						if (it_buckethead->getX() == 15) {
							instance.clearScreen();
							instance.gameOver();
						}
					}
				}
			}

		}
	}
}
