#include "CPlant.h"




void CPlant::destroyPlant(int line, int column, UserInterface::CField& game)
{
	game.clear_on_field(line, column);
}

/*CPlant::CPlant(UserInterface::CField& game, int line, int column,  int damage)
{
	if (game.check_field(line, column) != ' ')
		game.add_on_field(type, line, column);
	this->line = line;
	this->column = column;
	this->hp = 100;
}
*/
CPlant::CPlant(int difficulty, UserInterface::CField& game, int line, int column, char type)
{
	if (difficulty == 1 && line == 3)
	{
		game.add_on_field(type, line, column);
		this->line = line;
		this->column = column;

	}
	else if (difficulty == 2 && (line%3>1 && line%3<5))
	{
		
		game.add_on_field(type, line, column);
		this->line = line;
		this->column=column;
	}
	else
	{
		game.add_on_field(type, line, column);
		this->line = line;
		this->column = column;
	}



}

CPlant::~CPlant()
{
}

void CPlant::taking_damage(int damage, UserInterface::CField& game)
{
	this->hp = this->hp - damage;
	if (this->hp <= 0) destroyPlant(this->line,this->column,game);
}

void CPlant::shoot(UserInterface::CField& game)
{

}

int CPlant::get_line()
{
	return line;
}

int CPlant::get_column()
{
	return column;
}

int CPlant::get_damage()
{
	return damage;
}

char CPlant::get_type()
{
	return type;
}
