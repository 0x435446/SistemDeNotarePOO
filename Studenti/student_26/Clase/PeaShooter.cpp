#include "PeaShooter.h"
#include"Zombie.h"
using namespace std::chrono;

void PeaShooter::MoveShots(Panel& panel, Zombie& zombie)
{
	if (!ShotList.empty())
	{
		for (auto shot : ShotList)
		{
			if ((*shot).getCenterOfDrawing().X <= panel.getPanelWidth())
			{
				(*shot).Move(panel);

				if ((*shot).getCenterOfDrawing().X == zombie.getCenterOfDrawing().X && (*shot).getCenterOfDrawing().Y == zombie.getCenterOfDrawing().Y)
				{
					this->fight(panel, zombie);
					this->Ability(panel);
					(*shot).Erase(panel);
					(*shot).destroy();
				}
			}
		}
	}
	ShotList.remove_if([&panel](Shot* shot) {return(*shot).getCenterOfDrawing().X >= panel.getPanelWidth(); });
}

void PeaShooter::Shoot(Panel& panel, Zombie& zombie)
{
	COORD Center = this->getCenterOfDrawing(); //de la pozitia initiala a plantei
	auto end = high_resolution_clock::now();
	if (duration_cast<milliseconds>(end - this->Start).count() > this->AttackSpeed)
	{
		this->Start = end;
		if (Center.X < zombie.getCenterOfDrawing().X && Center.Y == zombie.getCenterOfDrawing().Y)
		{
			Shot* newshot = new ShotPea(Center);//se creeaza un shot
			ShotList.push_back(newshot); //se adauga shot ul la lista
		}
	}
	MoveShots(panel, zombie);//se muta shoturile existente
}

bool PeaShooter::Draw(Panel& panel)
{
	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == SPACE)
	{
		//panel.setChar(Center.X - 1, Center.Y - 1, this->cSign);
		panel.setChar(Center.X - 1, Center.Y, this->cSign);
		panel.setChar(Center.X - 1, Center.Y + 1, this->cSign);
		//panel.setChar(Center.X, Center.Y - 1, this->cSign);
		panel.setChar(Center.X, Center.Y, this->cSign);
		//panel.setChar(Center.X, Center.Y + 1, this->cSign);
		//panel.setChar(Center.X + 1, Center.Y - 1, this->cSign);
		//panel.setChar(Center.X + 1, Center.Y, this->cSign);
		//panel.setChar(Center.X + 1, Center.Y + 1, this->cSign);
		return 1;
	}
	else
	{
		return 0;
	}
}

bool PeaShooter::Erase(Panel& panel)
{
	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == this->cSign)
	{
		//panel.setChar(Center.X - 1, Center.Y - 1, SPACE);
		panel.setChar(Center.X - 1, Center.Y, SPACE);
		panel.setChar(Center.X - 1, Center.Y + 1, SPACE);
		//panel.setChar(Center.X, Center.Y - 1, SPACE);
		panel.setChar(Center.X, Center.Y, SPACE);
		//panel.setChar(Center.X, Center.Y + 1, SPACE);
		//panel.setChar(Center.X + 1, Center.Y - 1, SPACE);
		//panel.setChar(Center.X + 1, Center.Y, SPACE);
		//panel.setChar(Center.X + 1, Center.Y + 1, SPACE);
		return 1;
	}
	else {
		return 0;
	}
}