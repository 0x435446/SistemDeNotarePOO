#include "RegularZombie.h"

bool RegularZombie::Draw(Panel& panel)
{
	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == SPACE)
	{
		//panel.setChar(Center.X - 1, Center.Y - 1, cSign);
		//panel.setChar(Center.X - 1, Center.Y, cSign);
		//panel.setChar(Center.X - 1, Center.Y + 1, cSign);
		panel.setChar(Center.X, Center.Y - 1, cSign);
		panel.setChar(Center.X, Center.Y, cSign);
	    panel.setChar(Center.X, Center.Y + 1, cSign);
		//panel.setChar(Center.X + 1,Center.Y - 1, cSign);
		//panel.setChar(Center.X + 1,Center.Y, cSign);
		//panel.setChar(Center.X + 1,Center.Y + 1, cSign);
		return 1;
	}
	else
	{
		return 0;
	}
}

bool RegularZombie::Erase(Panel& panel)
{
	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == cSign)
	{
		//panel.setChar(Center.X - 1, Center.Y - 1, SPACE);
		//panel.setChar(Center.X - 1, Center.Y, SPACE);
		//panel.setChar(Center.X - 1, Center.Y + 1, SPACE);
		panel.setChar(Center.X, Center.Y - 1, SPACE);
		panel.setChar(Center.X, Center.Y, SPACE);
		panel.setChar(Center.X, Center.Y + 1, SPACE);
		//panel.setChar(Center.X + 1, Center.Y - 1, SPACE);
		//panel.setChar(Center.X + 1,Center.Y, SPACE);
		//panel.setChar(Center.X + 1, Center.Y + 1, SPACE);
		return 1;
	}
	else
	{
		return 0;
	}
}
