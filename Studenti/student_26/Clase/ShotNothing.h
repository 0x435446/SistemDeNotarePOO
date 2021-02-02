#pragma once
#include "Shot.h"
class ShotNothing :
	public Shot
{
	virtual void Move(Panel&) override {}
};

