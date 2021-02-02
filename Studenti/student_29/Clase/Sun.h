#pragma once
#include "Resource.h"

class Sun final : public Resource
{
	int x;
	int y;
	char ch = '*';

public:
	Sun(const int&, const int&);
	int posX() const { return x; };
	int posY() const { return y; };
	~Sun();
};

