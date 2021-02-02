#include "Sun.h"

int Sun::nResources = 100;

bool Sun::Draw(Panel& panel)
{
	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == L'.')
	{
		panel.setChar(Center.X - 1, Center.Y, L'x');
		panel.setChar(Center.X, Center.Y - 1, L'x');
		panel.setChar(Center.X, Center.Y, L'x');
		panel.setChar(Center.X, Center.Y + 1, L'x');
		panel.setChar(Center.X + 1, Center.Y, L'x');
		return 1;
	}
	else
	{
		return 0;
	}

}

bool Sun::Erase(Panel& panel)
{
	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == L'x')
	{
		nResources += this->nVal;

		panel.setChar(Center.X - 1, Center.Y, L'.');
		panel.setChar(Center.X, Center.Y - 1, L'.');
		panel.setChar(Center.X, Center.Y, L'.');
		panel.setChar(Center.X, Center.Y + 1, L'.');
		panel.setChar(Center.X + 1, Center.Y, L'.');
		return 1;
	}
	else
	{
		return 0;
	}
}