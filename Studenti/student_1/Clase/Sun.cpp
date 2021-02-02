#include "Sun.h"

using namespace GameMechanics;

Sun::Sun(int rowUp, int colLeft) : Resource(rowUp, colLeft)
{
	this->ID = EntityID::SUN;

	auto index = getIndex(RESOURCES_ID, this->ID);

	this->resourcePoints = RESOURCE_POINTS[index];
	this->width = UserInterface::SUN_WIDTH;
}


Sun::~Sun()
{
}


std::string Sun::serialize()
{
	using namespace std;

	string s = "Sun\n";

	s += to_string(this->rowUp);
	s += " ";
	s += to_string(this->colLeft);
	s += "\n";

	return s;

}