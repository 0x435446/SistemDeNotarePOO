#include "CZombie.h"
#include<random>
CZombie::CZombie()
{
}
CZombie::CZombie(int difficulty, UserInterface::CField& game,char type)
{
	if (difficulty == 1)
	{
		game.add_on_field(type, 3, 9);
		line = 3;
		column = 9;
	}
	else if (difficulty == 2)
	{
		line = rand() % 3 + 2;
		while(game.check_field(line,9)!=' ')
			line = rand() % 3 + 2;
		game.add_on_field(type, line, 9);
		 
		column = 9;
	}
	else
	{
		line = rand() % 5 + 1;
		while (game.check_field(line, 9) != ' ')
			line = rand() % 5 + 1;
		game.add_on_field(type,line, 9);
		column = 9;
	}

}

void CZombie::make_damage(UserInterface::CField& game,int line, int column)
{
	if ((game.check_field(line, column - 1) == 'P')||(game.check_field(line, column - 1) != 'F')||
		(game.check_field(line, column - 1) != 'W')||(game.check_field(line, column - 1) != 'C'||
		(game.check_field(line, column - 1) != 'I')))
	{

	}
}

void CZombie::destroyZombie()
{
}

void CZombie::moveZombie(UserInterface::CField& game)
{
	if ((game.check_field(line, column - 1) != 'P') && (game.check_field(line, column - 1) != 'F') &&
		(game.check_field(line, column - 1) != 'W') && (game.check_field(line, column - 1) != 'C') &&
		(game.check_field(line, column - 1) != 'I'))
	{
		if (game.check_field(line, column - 1) == ' ' && column > 1)
		{
			game.add_on_field(type, line, column - 1);
			game.clear_on_field(line, column);
			column--;
		}	
	}
	else if (column == 1)
	{
		game.game_over();
	}
	
	else
	{
		make_damage(game, line, column - 1);
	}
		
}

char CZombie::get_type()
{
	return type;
}

int CZombie::get_line()
{
	return line;
}

int CZombie::get_column()
{
	return column;
}

int CZombie::get_damage(int damage)
{
	this->hp = this->hp- damage;
	return this->hp;
}
