#pragma once
#include "Shot.h"

class ShotPea :
	public Shot
{
protected:
	ShotPea(wchar_t cSign, COORD Center) :Shot(cSign, Center) {}
public:
	ShotPea(COORD Center) :Shot(PEASHOT, Center) {}
	~ShotPea(){}
	//Efect
	virtual void Move(Panel&) override;
	//Behavior
	virtual bool Draw(Panel& panel) override;
	virtual bool Erase(Panel& panel) override;
};
