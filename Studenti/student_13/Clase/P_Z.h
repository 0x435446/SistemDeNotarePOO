#pragma once
#include<vector>

#include"IPlant.h"
#include"CZombie.h"
#include"CBullet.h"

class P_Z
{
public:
	P_Z();

	IZombie* create_normal_zombie(int difficulty, UserInterface::CField& game);
	IZombie* create_buckethead_zombie(int difficulty, UserInterface::CField& game);
	IPlant* create_peashooter(int difficulty, UserInterface::CField& game, int line, int column);
	IPlant* create_sunflower(int difficulty, UserInterface::CField& game, int line, int column);
	CBullet* create_bullet(UserInterface::CField& game, int line, int column, int damage);
	
	void add_bullet(CBullet& bullet);
	void add_zombie(IZombie& zombie);
	void add_plant(IPlant& plant);
	void move_zombies(UserInterface::CField& game);
	void move_bullets(UserInterface::CField& game);
	void shoot(UserInterface::CField& game);

private:
	std::vector<IZombie*> lista_zombie;
	std::vector<IPlant*> lista_plants;
	std::vector<CBullet*> lista_bullets;
	int number_of_zombie;

};

