#include "Resource.h"

using namespace GameMechanics;

Resource::Resource(int rowUp, int colLeft) : Entity(rowUp, colLeft)
{
}


Resource::~Resource()
{
}

unsigned GameMechanics::Resource::collectResources()
{
	return resourcePoints;
}

