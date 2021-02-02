#pragma once
#include"CField.h"

using namespace UserInterface;

class CBullet
{
public:
	CBullet(UserInterface::CField& game, int line, int column, int damage);
	void move_bullets(UserInterface::CField& game);
	int damage;
	int line;
	int column;
};

