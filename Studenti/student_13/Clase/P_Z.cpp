#include "P_Z.h"
#include"CNormalZombie.h"
#include"CBucketHeadZombie.h"
#include"CPeaShooter.h"
#include"CSunFlower.h"


P_Z::P_Z()
{
	number_of_zombie = 15;
}

IZombie* P_Z::create_normal_zombie(int difficulty, UserInterface::CField& game)
{
	CNormalZombie*zombie = NULL;
	zombie = new CNormalZombie(difficulty,game,'Z');
	zombie->type = 'Z';
	zombie->damage = 10;
	zombie->hp = 50;
	return zombie;
}

IZombie* P_Z::create_buckethead_zombie(int difficulty, UserInterface::CField& game)
{
	CBucketHeadZombie* zombie = NULL;
	zombie = new CBucketHeadZombie(difficulty, game, 'B');
	zombie->type = 'B';
	zombie->damage = 5;
	zombie->hp = 80;
	return zombie;
}

IPlant* P_Z::create_peashooter(int difficulty, UserInterface::CField& game,int line, int column)
{
	if (game.get_resurse() < 150)
	{
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		conOut(37, 0) << "Not enough SUN";
		return nullptr;
	}
	game.decrease_resurse(150);
	CPeaShooter* plant = NULL;
	plant = new CPeaShooter(difficulty, game, line, column, 'P');
	plant->hp = 100;
	plant->damage = 20;
	plant->type = 'Z';
	return plant;
}

IPlant* P_Z::create_sunflower(int difficulty, UserInterface::CField& game, int line, int column)
{
	if (game.get_resurse() < 250)
	{
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		conOut(37, 0) << "Not enough SUN";
		return nullptr;
	}
	game.decrease_resurse(250);
	CSunFlower* plant = NULL;
	plant = new CSunFlower(difficulty, game, line,column,'F');
	plant->hp = 150;
	plant->damage = 0;
	plant->type = 'F';
	return plant;
}

CBullet* P_Z::create_bullet(UserInterface::CField& game, int line, int column, int damage)
{
	if (game.check_field(line, column + 1) == ' ')
	{
		CBullet* bullet=NULL;
		bullet = new CBullet(game, line, column+1, damage);
		return bullet;
	}
	else
	{
		//make damage to zombie
	}
}


void P_Z::add_bullet(CBullet& bullet)
{
	if(&bullet!=NULL)
	this->lista_bullets.push_back(&bullet);
}

void P_Z::add_zombie(IZombie& zombie)
{
	if (&zombie != NULL)
	{


		this->lista_zombie.push_back(&zombie);
	}
}

void P_Z::add_plant(IPlant& plant)
{
	if (&plant != NULL)
	this->lista_plants.push_back(&plant);
}

void P_Z::move_zombies(UserInterface::CField& game)
{
	for (int i = 0; i < lista_zombie.size(); i++)
	{
		
		lista_zombie[i]->moveZombie(game);
	}
}

void P_Z::move_bullets(UserInterface::CField& game)
{
	for (int i = 0; i < lista_bullets.size(); i++)
	{

		if (game.check_field(lista_bullets[i]->line, lista_bullets[i]->column) != ' ')
		{
			lista_bullets[i]->move_bullets(game);
			if (game.check_field(lista_bullets[i]->line, lista_bullets[i]->column + 1) == 'P' || game.check_field(lista_bullets[i]->line, lista_bullets[i]->column + 1) == 'F')
			{
				game.remove_bullet(lista_bullets[i]->line, lista_bullets[i]->column);
				//lista_bullets.erase(lista_bullets.begin() + i);
			}
			else if (game.check_field(lista_bullets[i]->line, lista_bullets[i]->column + 1) == 'Z' || game.check_field(lista_bullets[i]->line, lista_bullets[i]->column+1) == 'B')
			{
				for (int j = 0; j < lista_zombie.size(); j++)
				{
					if ((lista_zombie[j]->get_line() == lista_bullets[i]->line) && (lista_zombie[j]->get_column() == (lista_bullets[i]->column + 1)))
					{
						if (lista_zombie[j]->get_damage(lista_bullets[i]->damage) <= 0)
						{
							lista_zombie.erase(lista_zombie.begin() + j);
							game.clear_on_field(lista_bullets[i]->line, lista_bullets[i]->column + 1);
							game.remove_bullet(lista_bullets[i]->line, lista_bullets[i]->column);
							//lista_bullets.erase(lista_bullets.begin() + i);
							number_of_zombie--;
							game.increase_score();
							if (number_of_zombie == 0)
							{
								UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
								for (int k = 0; k < 40; k++)
									for (int l = 0; l <= 160; l++)
									{
										if (k == 0 && l == 0) conOut(0, 0) << ' ';
										else conOut << ' ';
									}
								conOut << "\n";

								conOut(20, 75) << "You Won!";
								while (true);
							}
							
						}
					}
				}
			}
		}
		else 
		{
			lista_bullets.erase(lista_bullets.begin()+i);
		}
	}
}

void P_Z::shoot(UserInterface::CField& game)
{
	for (int i = 0; i < lista_plants.size(); i++)
	{
		if (lista_plants[i]->get_type() != 'F')
		{
			if (game.check_field(lista_plants[i]->get_line(), lista_plants[i]->get_column() + 1) == ' ')
				add_bullet(*create_bullet(game, lista_plants[i]->get_line(), lista_plants[i]->get_column(), lista_plants[i]->get_damage()));
			else
			{
				//make damage to zombie
				if (game.check_field(lista_plants[i]->get_line(), lista_plants[i]->get_column() + 1) == 'Z' || game.check_field(lista_plants[i]->get_line(), lista_plants[i]->get_column() + 1) == 'B')
					for (int j = 0; j < lista_zombie.size(); j++)
					{
						if ((lista_zombie[j]->get_line() == lista_plants[i]->get_line()) && (lista_zombie[j]->get_column() == (lista_plants[i]->get_column() + 1)))
						{
							if (lista_zombie[j]->get_damage(lista_plants[i]->get_damage()) <= 0)
							{
								lista_zombie.erase(lista_zombie.begin() + j);
								game.clear_on_field(lista_plants[i]->get_line(), lista_plants[i]->get_column() + 1);
								game.increase_score();
								number_of_zombie--;
								if (number_of_zombie <= 0)
								{
									UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
									for (int i = 0; i < 40; i++)
										for (int j = 0; j <= 160; j++)
										{
											if (i == 0 && j == 0) conOut(0, 0) << ' ';
											else conOut << ' ';
										}
									conOut << "\n";

									conOut(20, 75) << "You Won!";
									while (true);
								}
							}
						}
					}
			}
		}
	}
}
