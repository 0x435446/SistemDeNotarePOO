#include "ShotPea.h"
using namespace std::chrono;

void ShotPea::Move(Panel& panel)
{
	COORD Center = this->PozitieInitiala;
	auto end = high_resolution_clock::now();

	if (duration_cast<milliseconds>(end - this->getStart()).count() > this->getShotMVS()/10)
	{
		this->setStart(end);


		this->nFrameCount++;
		if (this->nFrameCount % 10 != 0)
		{
			this->Draw(panel);
		}
		else
		{
			this->Erase(panel);
			nOffsetShot++;
			Center.X += nOffsetShot;
			this->setCenterOfDrawing(Center);
		}
	}
}

bool ShotPea::Draw(Panel& panel)
{
	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == SPACE)
	{
		panel.setChar(Center.X, Center.Y, this->cSign);
		return 1;
	}
	else
	{
		return 0;
	}
}

bool ShotPea::Erase(Panel& panel)
{
	COORD Center = this->getCenterOfDrawing();
	if (panel.getChar(Center.X, Center.Y) == this->cSign)
	{
		panel.setChar(Center.X, Center.Y, SPACE);
		return 1;
	}
	else
	{
		return 0;
	}
}
