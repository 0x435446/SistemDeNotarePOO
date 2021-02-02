#include "WallNut.h"

bool WallNut::Draw(Panel& panel)
{

	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == SPACE)
	{
		//panel.setChar(Center.X - 1, Center.Y - 1, WALLNUT);
		//panel.setChar(Center.X - 1, Center.Y, WALLNUT);
		//panel.setChar(Center.X - 1, Center.Y + 1, WALLNUT);
		panel.setChar(Center.X, Center.Y - 1, WALLNUT);
		panel.setChar(Center.X, Center.Y, WALLNUT);
		panel.setChar(Center.X, Center.Y + 1, WALLNUT);
		panel.setChar(Center.X + 1, Center.Y - 1, WALLNUT);
		panel.setChar(Center.X + 1, Center.Y, WALLNUT);
		panel.setChar(Center.X + 1, Center.Y + 1, WALLNUT);
		return 1;
	}
	else
	{
		return 0;
	}
}

bool WallNut::Erase(Panel& panel)
{

	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == WALLNUT)
	{
		//panel.setChar(Center.X - 1, Center.Y - 1, SPACE);
		//panel.setChar(Center.X - 1, Center.Y, SPACE);
		//panel.setChar(Center.X - 1, Center.Y + 1, SPACE);
		panel.setChar(Center.X, Center.Y - 1, SPACE);
		panel.setChar(Center.X, Center.Y, SPACE);
		panel.setChar(Center.X, Center.Y + 1, SPACE);
		panel.setChar(Center.X + 1, Center.Y - 1, SPACE);
		panel.setChar(Center.X + 1, Center.Y, SPACE);
		panel.setChar(Center.X + 1, Center.Y + 1, SPACE);
		return 1;
	}
	else
	{
		return 0;
	}
}
