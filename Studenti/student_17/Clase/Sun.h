#pragma once
#include "Resource.h"

#define SUN_VALUE 100

class Sun : public Resource
{
public:
	Sun(const int x, const int y);
	~Sun();
};