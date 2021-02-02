#include "Terrain.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <random>

using namespace std;

Terrain* Terrain::instance = nullptr;

void gotoXY(const int& a, const int& b)
{
	COORD coord;
	coord.X = b;
	coord.Y = a;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Terrain::~Terrain()
{
}

Terrain& Terrain::getTerrain(const unsigned int& lv)
{
	if (!instance)
	{
		instance = new Terrain(lv);
	}
	return (*instance);
}

void Terrain::deleteTerrain()
{
	delete instance;
	instance = nullptr;
	this->~Terrain();
}

Terrain::Terrain(const unsigned int& lv) : rows(23), columns(68), level(lv), zombie_counter(0), bucket_head_counter(0)
{	
	(*this->logger) = UserInterface::Log::getLogger();

	(*logger).write("Initialize terrain.");

	matrix = new char*[rows];

	for (int i = 0; i < 9; i++)
	{
		s[i] = 0;
	}

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new char[columns];
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = ' ';
		}
	}

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			if (c % 7 == 0 && r % 4 == 0)
			{
				matrix[r][c] = 201; //colt stanga sus
				matrix[r][c + 4] = 187; //colt dreapta sus
				matrix[r + 2][c] = 200; //colt stanga jos
				matrix[r + 2][c + 4] = 188; //colt dreapta jos

				matrix[r][c + 1] = 205;
				matrix[r][c + 2] = 205;
				matrix[r][c + 3] = 205;
				matrix[r + 2][c + 1] = 205;
				matrix[r + 2][c + 2] = 205;
				matrix[r + 2][c + 3] = 205;

				matrix[r + 1][c] = 186;
				matrix[r + 1][c + 4] = 186;
			}
		}
	}

	matrix[0][0] = 'S';
	matrix[0][1] = 'c';
	matrix[0][2] = 'o';
	matrix[0][3] = 'r';
	matrix[0][4] = 'e';
	matrix[1][0] = 'B';
	matrix[1][1] = 'o';
	matrix[1][2] = 'a';
	matrix[1][3] = 'r';
	matrix[1][4] = 'd';
	matrix[2][0] = ' ';  //folosite pentru scor
	matrix[2][1] = ' ';
	matrix[2][2] = ' ';
	matrix[2][3] = ' ';
	matrix[2][4] = ' ';

	matrix[5][2] = 'F';
	matrix[9][2] = 'P'; // folosite pentru shop
	matrix[13][2] = 'W';
	matrix[17][2] = 'C';
	matrix[21][2] = 'S';

	if (level == 1)
	{
		for (int r = 8; r < rows; r++)
		{
			for (int c = 5; c < columns; c++)
			{
				matrix[r][c] = ' ';
			}
		}
	}
	if (level == 3)
	{
		for (int r = 16; r < rows; r++)
		{
			for (int c = 5; c < columns; c++)
			{
				matrix[r][c] = ' ';
			}
		}
	}
	if (level == 5)
	{
		return;
	}
}

void Terrain::generateTerrain()
{
	(*logger).write("Generate terrain.");

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}

	gotoXY(4, 7);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 2);

	for (int i = 4; i < rows; i++)
	{
		for (int j = 7; j < columns; j++)
		{
			cout << matrix[i][j];
		}
		gotoXY(i + 1, 7);
	}

	SetConsoleTextAttribute(hConsole, 4);
}

void Terrain::entitiesStillAlive()
{
	(*logger).write("Checking which entity is stil alive.");

	int entities_number = this->entity_list.size();

	for (int i = 0; i < entities_number; i++)
	{
		if (!this->entity_list[i]->isAlive())
		{
			matrix[this->entity_list[i]->posX()][this->entity_list[i]->posY()] = ' ';
			gotoXY(this->entity_list[i]->posX(), this->entity_list[i]->posY());
			std::cout << ' ';

			if (this->entity_list[i]->isMoovable())
			{
				score += 10;
			}

			this->entity_list.erase(this->entity_list.begin() + i);
			return;
		}
	}
}

void Terrain::printEntities()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);

	(*logger).write("Update entities.");

	int lane_x = 5;

	int entities_number = this->entity_list.size();

	char obstacle[5] = { 'F', 'P', 'W', 'C', 'S' };
	bool hitOrNot = false;;

	for (int i = 0; i < entities_number; i++)
	{
		gotoXY(this->entity_list[i]->posX(), this->entity_list[i]->posY());
		if (!this->entity_list[i]->isMoovable())
		{
			SetConsoleTextAttribute(hConsole, 7);
			std::cout << this->entity_list[i]->showSymbol();
			gotoXY(this->entity_list[i]->posX(), this->entity_list[i]->posY());
			SetConsoleTextAttribute(hConsole, 4);
		}
		if (this->entity_list[i]->isMoovable())
		{
			std::cout << ' ';
			matrix[this->entity_list[i]->posX()][this->entity_list[i]->posY()] = ' ';
			
			for (int j = 0; j < 5; j++)
			{
				if (matrix[this->entity_list[i]->posX()][this->entity_list[i]->posY() - 1] == obstacle[j])
				{
					hitOrNot = true;
					// aici am adus modificarile pt cherry
					/*if (obstacle[j] == 'C')
					{
						for (int k = 0; k < entities_number; k++)
						{
							if (this->entity_list[k]->posX() == this->entity_list[i]->posX() && this->entity_list[k]->posY() == this->entity_list[i]->posY() - 1)
							{
								this->entity_list[k]->damage(10);

								for (int l = 0; l < entities_number; l++)
								{
									if (this->entity_list[l]->posX() == this->entity_list[k]->posX() 
										&& this->entity_list[l]->posY() >= this->entity_list[k]->posY() - 3 
										&& this->entity_list[l]->posY() <= this->entity_list[k]->posY() + 3)
									{
										this->entity_list[l]->damage(this->entity_list[k]->getDmg());
									}
									if (this->entity_list[l]->posX() >= this->entity_list[k]->posX() - 5
										&& this->entity_list[l]->posX() <= this->entity_list[k]->posX() + 5
										&& this->entity_list[l]->posY() >= this->entity_list[k]->posX() - 8
										&& this->entity_list[l]->posY() <= this->entity_list[k]->posY() + 8)
									{
										this->entity_list[l]->damage(this->entity_list[k]->getDmg());
									}
								}
								break;
							}
						}
					}*/
				}
			}
			if (hitOrNot == false)
			{
				this->entity_list[i]->move();
			}
			else
			{
				for (int j = 0; j < entities_number; j++)
				{
					if (this->entity_list[j]->posX() == this->entity_list[i]->posX() && this->entity_list[j]->posY() == this->entity_list[i]->posY() - 1)
					{
						this->entity_list[j]->damage(this->entity_list[i]->getDmg());
					}
				}
			}
			hitOrNot = false;
			gotoXY(this->entity_list[i]->posX(), this->entity_list[i]->posY());
			matrix[this->entity_list[i]->posX()][this->entity_list[i]->posY()] = this->entity_list[i]->showSymbol();
			std::cout << this->entity_list[i]->showSymbol();
		}
	}

	int peas_number = this->peas.size();
	char pea_ch = 248;
	int* proj_hit = new int[32];
	int proj_hit_counter = 0;

	for (int i = 0; i < peas_number; i++)
	{
		gotoXY(this->peas[i].posX(), this->peas[i].posY());
		std::cout << ' ';
		if (matrix[peas[i].posX()][peas[i].posY()] == 'z' || matrix[peas[i].posX()][peas[i].posY()] == 'b' || 
			matrix[peas[i].posX()][peas[i].posY() + 1] == 'z' || matrix[peas[i].posX()][peas[i].posY() + 1] == 'b' ||
			matrix[peas[i].posX()][peas[i].posY() - 1] == 'z' || matrix[peas[i].posX()][peas[i].posY() - 1] == 'b')
		{
			proj_hit[proj_hit_counter] = i;
			proj_hit_counter++;

			for (int k = 0; k < entities_number; k++)
			{
				if (peas[i].posX() == entity_list[k]->posX() && peas[i].posY() == entity_list[k]->posY())
				{
					entity_list[k]->damage(peas[i].dealtDamage());
				}
			}
		}
		else
		{
			if (peas[i].posY() == 67)
			{
				proj_hit[proj_hit_counter] = i;
				proj_hit_counter++;
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 6);
				this->peas[i].move();
				gotoXY(this->peas[i].posX(), this->peas[i].posY());
				std::cout << pea_ch;
			}
		}
	}

	for (int i = proj_hit_counter - 1; i >= 0; i--)
	{
		this->peas.erase(this->peas.begin() + proj_hit[i]);
	}

	SetConsoleTextAttribute(hConsole, 7);
}

void Terrain::setAvailablePlantSlots()
{
	if (level == 1)
	{
		int c = 9;

		for (int i = 1; i <= 9; i++)
		{
			available_plant_slots.push_back(make_pair(5, c));
			c += 7;
		}
	}
	if (level == 3)
	{
		int c = 9;

		for (int i = 1; i <= 9; i++)
		{
			available_plant_slots.push_back(make_pair(5, c));
			available_plant_slots.push_back(make_pair(9, c));
			available_plant_slots.push_back(make_pair(13, c));
			c += 7;
		}
		
	}
	if (level == 5)
	{
		int c = 9;

		for (int i = 1; i <= 9; i++)
		{
			available_plant_slots.push_back(make_pair(5, c));
			available_plant_slots.push_back(make_pair(9, c));
			available_plant_slots.push_back(make_pair(13, c));
			available_plant_slots.push_back(make_pair(17, c));
			available_plant_slots.push_back(make_pair(21, c));
			c += 7;
		}
	}

}

void Terrain::setAvailableSunSlots()
{
	int c = 9;

	for (int i = 1; i <= 9; i++)
	{
		available_sun_slots.push_back(make_pair(1, c));
		c += 7;
	}
}

void Terrain::setShopSlots()
{
	shop_slots.push_back(make_pair(5, 2));
	shop_slots.push_back(make_pair(9, 2));
	shop_slots.push_back(make_pair(13, 2));
	shop_slots.push_back(make_pair(17, 2));
	shop_slots.push_back(make_pair(21, 2));
}

int Terrain::numberOfSunflowers()
{
	int counter = 0;

	for (int i = 0; i < this->entity_list.size(); i++)
	{
		if (this->entity_list[i]->showSymbol() == 'F')
		{
			counter++;
		}
	}

	return counter;
}

void Terrain::entityAtacks()
{
	int entities_number = this->entity_list.size();

	for (int i = 0; i < entities_number; i++)
	{
		if (this->entity_list[i]->doesHaveNormalPeas())
		{
			Pea* p = new Pea(this->entity_list[i]->posX(), this->entity_list[i]->posY()+1);
			this->peas.push_back(*p);
		}
	}
}

void Terrain::generateSuns()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);

	int counter = 0;
	int pos[9] = { 9, 16, 23, 30, 37, 44, 51, 58, 65 };
	for (int i = 0; i < 9; i++) //verific mai intai daca nu cumva toate sloturile sunt ocupate cu obiecte de tip Sun
	{
		if (s[i] == 1)
			counter++;
		if (s[i] != 1)
			break;
		if (counter == 9)
			return;
	}
	while (1)
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist9(0, 8); // distribution in range [0, 8]

		int number = dist9(rng);

		if (!s[number])
		{
			Sun* temp = new Sun(1, pos[number]);
			this->updateSunSlots("new", *temp, number);

			COORD coord;
			coord.X = pos[number];
			coord.Y = 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			std::cout << '*';

			return;
		}
	}

	SetConsoleTextAttribute(hConsole, 7);
}

void Terrain::generateZombies()
{
	int lane_y = this->columns;
	int lane_x_level_1 = 5;
	int lane_x_level_3[3] = { 5,9,13 };
	int lane_x_level_5[5] = { 5,9,13,17,21 };

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist5(0, 4); 
	std::uniform_int_distribution<std::mt19937::result_type> dist3(0, 2);

	int lane;

	if (this->level == 1)
	{
		if (zombie_counter == 2)
			return;
		Entity* zombie = new NormalZombie(lane_x_level_1, lane_y, 'z');
		zombie_counter++;
		entity_list.push_back(zombie);
	}
	if (this->level == 3)
	{
		if (zombie_counter == 3)
			return;
		lane = dist3(rng);
		Entity* zombie = new NormalZombie(lane_x_level_3[lane], lane_y, 'z');
		zombie_counter++;
		entity_list.push_back(zombie);
	}
	if (this->level == 5)
	{
		if (zombie_counter == 4)
			return;
		lane = dist5(rng);
		Entity* zombie = new NormalZombie(lane_x_level_5[lane], lane_y, 'z');
		zombie_counter++;
		entity_list.push_back(zombie);
	}
}

void Terrain::generateBucketHeadZombies()
{
	int lane_y = this->columns;
	int lane_x_level_1 = 5;
	int lane_x_level_3[3] = { 5,9,13 };
	int lane_x_level_5[5] = { 5,9,13,17,21 };

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist5(0, 4);
	std::uniform_int_distribution<std::mt19937::result_type> dist3(0, 2);

	int lane;

	if (this->level == 1)
	{
		if (bucket_head_counter == 0)
			return;
		Entity * zombie = new BucketHead(lane_x_level_1, lane_y, 'b');
		entity_list.push_back(zombie);
	}
	if (this->level == 3)
	{
		if (bucket_head_counter == 1)
			return;
		lane = dist3(rng);
		Entity * zombie = new BucketHead(lane_x_level_3[lane], lane_y, 'b');
		bucket_head_counter++;
		entity_list.push_back(zombie);
	}
	if (this->level == 5)
	{
		if (bucket_head_counter == 2)
			return;
		lane = dist5(rng);
		Entity* zombie = new BucketHead(lane_x_level_5[lane], lane_y, 'b');
		bucket_head_counter++;
		entity_list.push_back(zombie);
	}
}

void Terrain::updateSunSlots(const std::string& command, const Sun& s, const int& slot_position)
{
	if (command == "new")
	{
		unavailable_sun_slots.push_back(make_pair(s.posX(), s.posY()));

		suns.push_back(s);

		this->s[slot_position] = 1;

		int size = available_sun_slots.size();
		for (int i = 0; i < size; i++)
		{
			if (available_sun_slots[i].first == s.posX() && available_sun_slots[i].second == s.posY())
			{
				available_sun_slots.erase(available_sun_slots.begin() + i);
				break;
			}
		}
	}
	else
	{
		if (command == "delete")
		{
			available_sun_slots.push_back(make_pair(s.posX(), s.posY()));

			this->s[slot_position] = 0;

			int size = unavailable_sun_slots.size();
			for (int i = 0; i < size; i++)
			{
				if (unavailable_sun_slots[i].first == s.posX() && unavailable_sun_slots[i].second == s.posY())
				{
					unavailable_sun_slots.erase(unavailable_sun_slots.begin() + i);
					suns.erase(suns.begin() + i);
					break;
				}
			}
		}
		else
		{
			throw "Error!";
		}
	}
	
}

void Terrain::updateSunSlots(const std::string& command, const int& x, const int& y)
{
	int pos[9] = { 9, 16, 23, 30, 37, 44, 51, 58, 65 };

	int slot_position;

	for (int i = 0; i < 9; i++)
	{
		if (pos[i] == y)
		{
			slot_position = i;
			break;
		}
	}

	s[slot_position] = 0;

	if (command == "delete")
	{
		available_sun_slots.push_back(make_pair(x, y));

		this->s[slot_position] = 0;

		int size = unavailable_sun_slots.size();
		for (int i = 0; i < size; i++)
		{
			if (unavailable_sun_slots[i].first == x && unavailable_sun_slots[i].second == y)
			{
				unavailable_sun_slots.erase(unavailable_sun_slots.begin() + i);
				suns.erase(suns.begin() + i);
				break;
			}
		}
	}
}

void Terrain::updatePlantSlots(const std::string& command, Entity* e)
{
	if (command == "new")
	{
		unavailable_plant_slots.push_back(make_pair(e->posX(), e->posY()));

		matrix[e->posX()][e->posY()] = e->showSymbol();

		entity_list.push_back(e);

		int size = available_plant_slots.size();
		for (int i = 0; i < size; i++)
		{
			if (available_plant_slots[i].first == e->posX() && available_plant_slots[i].second == e->posY())
			{
				available_plant_slots.erase(available_plant_slots.begin() + i);
				break;
			}
		}
	}
	else
	{
		if (command == "delete")
		{
			matrix[e->posX()][e->posY()] = ' ';

			available_plant_slots.push_back(make_pair(e->posX(), e->posY()));
			int size = unavailable_plant_slots.size();
			for (int i = 0; i < size; i++)
			{
				if (unavailable_plant_slots[i].first == e->posX() && unavailable_plant_slots[i].second == e->posY())
				{
					unavailable_plant_slots.erase(unavailable_plant_slots.begin() + i);
					entity_list.erase(entity_list.begin() + i);
					break;
				}
			}
		}
		else
		{
			throw "Error!";
		}
	}
}