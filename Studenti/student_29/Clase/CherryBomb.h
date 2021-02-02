#pragma once
#include "Plant.h"
class CherryBomb final : public Plant
{
public:
	CherryBomb(const unsigned int&, const unsigned int&, char);
	void attack() override;
	~CherryBomb();
};

