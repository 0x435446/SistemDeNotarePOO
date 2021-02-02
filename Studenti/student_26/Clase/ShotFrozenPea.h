#pragma once
#include "ShotPea.h"
class ShotFrozenPea :
	public ShotPea
{
public:
	ShotFrozenPea(COORD Center) :ShotPea(FROZENPEASHOT, Center) {};
	~ShotFrozenPea() {};
};

