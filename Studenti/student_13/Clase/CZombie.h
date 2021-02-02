#pragma once
#include "IZombie.h"
class CZombie :
	public IZombie
{
public:

	CZombie();
	CZombie(int difficulty, UserInterface::CField& game,char type);
	void make_damage(UserInterface::CField& game,int line, int column);
	void destroyZombie() ;
	void moveZombie(UserInterface::CField& game) ;
	char get_type();
	int get_line();
	int get_column();
	int get_damage(int damage);


	int damage;
	int hp;
	char type;
	int line;
	int column;

};

  