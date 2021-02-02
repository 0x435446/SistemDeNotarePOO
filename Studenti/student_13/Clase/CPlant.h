#pragma once
#include "IPlant.h"
#include"CBullet.h"
class CPlant :
	public IPlant
{
public:
	CPlant(int difficulty, UserInterface::CField& game, int line, int column, char type);
	~CPlant();
	void destroyPlant(int line, int column, UserInterface::CField& game);
	void taking_damage(int damage, UserInterface::CField& game);
	void shoot(UserInterface::CField& game);
	int get_line();
	int get_column();
	int get_damage();
	char get_type() ;


	int hp;
	int damage;
	int line;
	int column;
	char type;
};

