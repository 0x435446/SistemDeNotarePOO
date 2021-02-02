#include "CBullet.h"

CBullet::CBullet(UserInterface::CField& game,int line, int column, int damage)
{
	game.add_bullet(line, column);
	this->line = line;
	this->column = column;
	this->damage = damage;
}

void CBullet::move_bullets(UserInterface::CField& game)
{
	 if (column == 9) game.remove_bullet(line, column); 
	
	else	if (game.check_field(line, column + 1) == ' ')
	 {

		 game.add_bullet(line, column + 1);
		 game.remove_bullet(line, column);
		 column++;
	 }
	else if (game.check_field(line, column + 1) == 'Z' || game.check_field(line, column + 1) == 'B' || game.check_field(line, column + 1) == 184)
	{
		//make damage to zombie




		 game.remove_bullet(line, column);
	}
}
