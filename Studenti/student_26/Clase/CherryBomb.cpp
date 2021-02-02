#include "CherryBomb.h"

bool CherryBomb::Draw(Panel& panel)
{
	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == SPACE)
	{
	   
		//Linia de Stanga
		//panel.setChar(Center.X - 1, Center.Y - 1, CHERRYBOMB);
		panel.setChar(Center.X - 1, Center.Y, L'x');
		panel.setChar(Center.X - 1, Center.Y + 1, CHERRYBOMB);
		//Linia de Mijloc
		panel.setChar(Center.X, Center.Y - 1, L'x');
		//panel.setChar(Center.X, Center.Y, CHERRYBOMB);
		//panel.setChar(Center.X, Center.Y + 1, CHERRYBOMB);
		//Linia de Dreapta
		//panel.setChar(Center.X + 1, Center.Y - 1, CHERRYBOMB);
		panel.setChar(Center.X + 1, Center.Y, L'x');
		panel.setChar(Center.X + 1, Center.Y + 1, CHERRYBOMB);
		return 1;
	}
	else
	{
		return 0;
	}
}

bool CherryBomb::Erase(Panel& panel)
{
	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == CHERRYBOMB)
	{
		//Linia de Stanga
		//panel.setChar(Center.X - 1, Center.Y - 1, SPACE);
		panel.setChar(Center.X - 1, Center.Y, L'x');
		panel.setChar(Center.X - 1, Center.Y + 1, SPACE);
		//Linia de Mijloc
		panel.setChar(Center.X, Center.Y - 1, L'x');
		//panel.setChar(Center.X, Center.Y, SPACE);
		//panel.setChar(Center.X, Center.Y + 1, SPACE);
		//Linia de Dreapta
		//panel.setChar(Center.X + 1, Center.Y - 1, SPACE);
		panel.setChar(Center.X + 1, Center.Y, L'x');
		panel.setChar(Center.X + 1, Center.Y + 1, SPACE);
		return 1;
	}
	else 
	{
		return 0;
	}
}
