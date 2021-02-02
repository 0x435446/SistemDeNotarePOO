#define _CRT_SECURE_NO_WARNINGS

#include "Action.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Afisare.h"
#include <string>

#define COST_PEA 80
#define COST_SUNFLOWER 100
#define COST_WALLNUT 50
#define COST_CHERRY 30
#define COST_FROZENPEA 120
#define BOARD_PLANT_Y 16
#define BOARD_PLANT_X 24
#define TIME_ACTIONS 1


Action::Action()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix[i][j] = new Entity;
		}
	}
}

Action::~Action()
{
}

Action & Action::getInstance()
{
	if (Action::instance == nullptr)
	{
		instance = new Action();
	}
	return *instance;
}

using namespace std::chrono;
int Action::place_plants(std::string action_one,int score, int level)
{
	static UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Afisare &checker = Afisare::getInstance();
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED );

	char cpy[100];
	char *p;
	int x_start, x_end, y_start, y_end;
	int contor = 0;   //verific daca am pus planta 
	int tip_planta; //1 pentru Pea , 2pt sunflower, 3 pt cherry, 4 pentru wallnut 5 pentru snow P.S.imi era lene sa fac char sau string
	int cost = 0;
	int cost_one = 0;

	strcpy(cpy, action_one.c_str());
	p = strtok(cpy, ": ");
	for (int j = 0; j < 3; j++)
	{
		p = strtok(NULL, ": (");
	}

	if (p)
	{

		if (strcmp(p, "double") == 0)
		{

			

			if (strcmp(p, "double") == 0)
			{

				for (int j = 1; j <= 3; j++)
				{
					p = strtok(NULL, " (");
				}
				x_start = atoi(p);
				p = strtok(NULL, ", ");
				y_start = atoi(p);
				
				//verific scor si coordonate 

				if ( ( (x_start>=10)&&(x_start<=18) )&&( (y_start>=16)&&(y_start<=19) ))
				{
					if (score>=COST_PEA)
					{
						cost = COST_PEA;
						contor = 1;
						tip_planta = 1;
					}
					else
					{
						double TimeToRunInSecs = 1;
						clock_t c = clock();
						while (double(clock() - c) / CLOCKS_PER_SEC < TimeToRunInSecs)
						{
							conOut(4, 45) << "Insufficient funds";
						}
						for (int i = 0; i < 20; i++)
						{
							conOut(4, 45 + i) << " ";
						}
					}
				}
				else if (((x_start >= 10) && (x_start <= 18)) && ((y_start >= 16 +5*1) && (y_start <= 19+5*1)))  //verific pt sunflower
				{
					if (score >= COST_SUNFLOWER)
					{
						cost = COST_SUNFLOWER;
						contor = 1;
						tip_planta = 2;
					}
					else
					{
						double TimeToRunInSecs = 1;
						clock_t c = clock();
						while (double(clock() - c) / CLOCKS_PER_SEC < TimeToRunInSecs)
						{
							conOut(4, 45) << "Insufficient funds";
						}
						for (int i = 0; i < 20; i++)
						{
							conOut(4, 45 + i) << " ";
						}
					}
				}
				else if (((x_start >= 10) && (x_start <= 18)) && ((y_start >= 16 + 5 * 2) && (y_start <= 19 + 5 * 2)))  //verific pt sunflower
				{
					if (score >= COST_CHERRY)
					{
						cost = COST_CHERRY;
						contor = 1;
						tip_planta = 3;
					}
					else
					{
						double TimeToRunInSecs = 1;
						clock_t c = clock();
						while (double(clock() - c) / CLOCKS_PER_SEC < TimeToRunInSecs)
						{
							conOut(4, 45) << "Insufficient funds";
						}
						for (int i = 0; i < 20; i++)
						{
							conOut(4, 45 + i) << " ";
						}
					}
				}
				else if (((x_start >= 10) && (x_start <= 18)) && ((y_start >= 16 + 5 * 3) && (y_start <= 19 + 5 * 3)))  //verific pt sunflower
				{
					if (score >= COST_WALLNUT)
					{
						cost = COST_WALLNUT;
						contor = 1;
						tip_planta = 4;
					}
					else
					{
						double TimeToRunInSecs = 1;
						clock_t c = clock();
						while (double(clock() - c) / CLOCKS_PER_SEC < TimeToRunInSecs)
						{
							conOut(4, 45) << "Insufficient funds";
						}
						for (int i = 0; i < 20; i++)
						{
							conOut(4, 45 + i) << " ";
						}
					}
				}
				else if (((x_start >= 10) && (x_start <= 18)) && ((y_start >= 16 + 5 * 4) && (y_start <= 19 + 5 * 4)))  //verific pt sunflower
				{
					if (score >= COST_FROZENPEA)
					{
						cost = COST_FROZENPEA;
						contor = 1;
						tip_planta = 5;
					}
					else
					{
						double TimeToRunInSecs = 1;
						clock_t c = clock();
						while (double(clock() - c) / CLOCKS_PER_SEC < TimeToRunInSecs)
						{
							conOut(4, 45) << "Insufficient funds";
						}
						for (int i = 0; i < 20; i++)
						{
							conOut(4, 45 + i) << " ";
						}
					}
				}

			}

			//aici verific al doilea set de coordonate si apelez functia sa printez 
			if (contor==1)
			{
				double TimeToRunInSecs = 1;
				clock_t c = clock();
				while (double(clock() - c) / CLOCKS_PER_SEC < TimeToRunInSecs)
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
					conOut(4, 45) << "Select where to place the plant";
				}
				for (int i = 0; i < 40; i++)
				{
					conOut(4, 45 + i) << " ";
				}

				do {
					std::string action_two = conIn.getUserActions();

					if (action_two != " ")
					{
						strcpy(cpy, action_two.c_str());
						p = strtok(cpy, " ");
						for (int j = 1; j <= 3; j++)
						{
							p = strtok(NULL, ": ");
						}
						if (p)
						{
							if (strcmp(p, "double") == 0)
							{

								for (int j = 1; j <= 3; j++)
								{
									p = strtok(NULL, " (");
								}
								x_end = atoi(p);
								p = strtok(NULL, ", ");
								y_end = atoi(p);


								//printez si fac matricea de i si j ==1  intru in afisare si trimit x si y ca parametru
								contor=checker.check_board(x_end, y_end, level, tip_planta);
								if (contor==0)
								{
									cost_one = cost;

								}
							}
						}

					}
				} while (contor == 1);

				
			}
			
		}
	}
	return cost_one;
}
void Action::plants_attack()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	std::string pea = "Pea";
	std::string aux;

	Afisare &printer = Afisare::getInstance();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			aux = matrix[i][j]->get_name();
			if (aux.compare(pea) == 0)
			{

				static auto begin = steady_clock::now();
				auto end = steady_clock::now();

				if (duration_cast<seconds>(end - begin).count() > 1)
				{
					begin = end;

					for (int k = 1; k < 9 - i; k++)
					{
						std::string auxiliar = matrix[i + k][j]->get_name();

						if (auxiliar.compare("default") == 0)
						{
							static auto begin = steady_clock::now();
							auto end = steady_clock::now();
							if (duration_cast<seconds>(end - begin).count() > 1 + k)
							{
								begin = end;


								matrix[i + k][j] = new PeaProjectile;
								matrix[i + k][j]->set_j(j, i + k);
								printer.print_Pea_projectile(i + k, j);

								break;
							}
						}
					}



				}
			}
		}
	}
}


using namespace std::chrono;
void Action::move_zombie()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	std::string zombie = "Zombie";
	std::string Bucket = "Bucket";
	std::string aux;
	float speed_zombie;

	Afisare &printer = Afisare::getInstance();
	
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			aux = matrix[i][j]->get_name();
			if (aux.compare(zombie)==0)
			{
				speed_zombie = get_time(i, j);
				static auto begin = steady_clock::now();
				auto end = steady_clock::now();

				if (duration_cast<seconds>(end - begin).count() > speed_zombie)
				{
					begin = end;
					std::string auxiliar = matrix[i - 1][j]->get_name();

					if ( auxiliar == "default")
					{
						delete matrix[i - 1][j];
						matrix[i - 1][j] = new Zombie;
						equal(matrix[i - 1][j], matrix[i][j]);
						printer.print_Zombie(i - 1, j);
						delete matrix[i][j];
						matrix[i][j] = new Entity;
						printer.delete_zombie(i, j);
					}

	
				}
			}
			else if (aux.compare(Bucket)==0)
			{
				speed_zombie = get_time(i, j);
				static auto begin = steady_clock::now();
				auto end = steady_clock::now();
				

					if (duration_cast<seconds>(end - begin).count() > speed_zombie)
					{
						
						begin = end;
						std::string auxiliar = matrix[i - 1][j]->get_name(); 

						if (auxiliar == "default")
						{
							delete matrix[i - 1][j];
							matrix[i - 1][j] = new Zombie_bucket;
							equal(matrix[i - 1][j], matrix[i][j]);
							printer.print_Bucket(i - 1, j);
							delete matrix[i][j];
							matrix[i][j] = new Entity;
							printer.delete_zombie(i, j);
						}
						
					}
			}
			else
			{

			}
		}
	}

}

int Action::end_game()
{
	std::string aux;
	std::string zombie = "Zombie";
	std::string Bucket = "Bucket";
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	Afisare &checker = Afisare::getInstance();

	for (int y = 0; y < 5; y++)
	{
		aux = matrix[0][2]->get_name();
		if (aux.compare(zombie)==0)
		{
			checker.print_lose();
			return 1;
		}
		if (aux.compare(Bucket) == 0)
		{
			checker.print_lose();
			return 1;
		}
	}
	return 0;
}

int Action::attack_zombie()
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	Afisare &printer = Afisare::getInstance();

	std::string zombie = "Zombie";
	std::string Bucket = "Bucket";
	std::string deff = "default";
	std::string aux;

	int attack;
	int health_plant;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			aux = matrix[i][j]->get_name();

			if ((aux.compare(zombie) == 0) || (aux.compare(Bucket)==0))
			{
				aux = matrix[i-1][j]->get_name();  //vad ce e in fata lui si intru doar daca nu e gol sau alt zombie
				if (!((aux.compare(deff) == 0) || (aux.compare(zombie) == 0) || (aux.compare(Bucket) == 0)))
				{

					health_plant = matrix[i - 1][j]->get_health();

					static auto begin = steady_clock::now();
					auto end = steady_clock::now();

					if (duration_cast<seconds>(end - begin).count() > TIME_ACTIONS)
					{
						begin = end;

						attack = matrix[i][j]->get_dmg();
						health_plant = matrix[i - 1][j]->get_health();
						if (health_plant >= attack)
						{
							matrix[i - 1][j]->set_health(health_plant - attack);
						}
						if (health_plant < attack)
						{
							delete matrix[i - 1][j];
							printer.delete_zombie(i - 1, j);
							matrix[i - 1][j] = new Entity;

							return 1;
						}

					}
				}
				
			}
			
		}
	}
	return 0;
}

void Action::equal(Entity* zombie_gol, Entity* zombie_vechi)
{

	int health = (*zombie_vechi).get_health();
	(*zombie_gol).set_health(health);


}

int Action::spawn_zobie(std::string type, int level, int previous_spawn)
{
	std::string name;
	Afisare &printer = Afisare::getInstance();
	int j;
	if (level==1)
	{
		j = 2;
	}
	name = matrix[8][j]->get_name();
	if (name == "default")
	{


		
		if (type == "Zombie")
		{
			delete matrix[8][j];
			matrix[8][j] = new Zombie;
			printer.print_Zombie(8, j);
			return 1;
			
		}
		else if (type == "Bucket")
		{
			delete matrix[8][j];
			matrix[8][j] = new Zombie_bucket;
			printer.print_Bucket(8, j);
			return 2;
			
		}
	}
	return previous_spawn;
}

WORD Action::GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}

Action* Action::instance = nullptr;