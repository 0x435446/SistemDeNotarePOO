#pragma once
#include"CField.h"

using namespace UserInterface;
class IZombie
{
public:
	IZombie() { ; }
	IZombie(int difficulty, UserInterface::CField& game,char type) { ; }
	virtual ~IZombie() { ; }

	
	virtual int get_line() = 0;
	virtual int get_column() = 0;
	virtual char get_type()=0;
	
	virtual int get_damage(int damage) = 0;
	virtual void destroyZombie() = 0;
	virtual void make_damage(UserInterface::CField& game,int line, int column) = 0;
	virtual void moveZombie(UserInterface::CField& game) = 0;
};

