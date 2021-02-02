#include "SunFlower.h"
bool SunFlower::Draw(Panel& panel)
{
	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == SPACE)
	{
		panel.setChar(Center.X - 1, Center.Y - 1, SUNFLOWER);
		panel.setChar(Center.X - 1, Center.Y, SUNFLOWER);
		//panel.setChar(Center.X - 1, Center.Y + 1, SUNFLOWER);
		panel.setChar(Center.X, Center.Y - 1, SUNFLOWER);
		panel.setChar(Center.X, Center.Y, SUNFLOWER);
		panel.setChar(Center.X, Center.Y + 1, L'p'); //doar estetic pt tulpina
		panel.setChar(Center.X + 1, Center.Y - 1, SUNFLOWER);
		panel.setChar(Center.X + 1, Center.Y, SUNFLOWER);
		//panel.setChar(Center.X + 1, Center.Y + 1, SUNFLOWER);
		return true;
	}
	else
	{
		return false;
	}
}

bool SunFlower::Erase(Panel& panel)
{
	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == SUNFLOWER)
	{
		panel.setChar(Center.X - 1, Center.Y - 1, SPACE);
		panel.setChar(Center.X - 1, Center.Y, SPACE);
		panel.setChar(Center.X - 1, Center.Y + 1, SPACE);
		panel.setChar(Center.X, Center.Y - 1, SPACE);
		panel.setChar(Center.X, Center.Y, SPACE);
		panel.setChar(Center.X, Center.Y + 1, SPACE);
		panel.setChar(Center.X + 1, Center.Y - 1, SPACE);
		panel.setChar(Center.X + 1, Center.Y, SPACE);
		panel.setChar(Center.X+1, Center.Y+1, SPACE);
		return 1;
	}
	else
	{
		return 0;
	}
}
