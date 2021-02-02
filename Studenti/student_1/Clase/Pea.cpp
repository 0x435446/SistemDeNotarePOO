#include "Pea.h"

using namespace GameMechanics;

Pea::Pea(int rowUp, int colLeft) :Projectile(rowUp, colLeft)
{
	this->ID = EntityID::PEA;

	auto index = getIndex(PROJECTILES_ID, this->ID);

	this->damage = PROJECTILES_DAMAGE[index];
	this->inflictableEffect = EffectInflicted::NONE;
	this->speed = PROJECTILES_SPEED[index];

	this->width = UserInterface::PEA_WIDTH;
}


Pea::~Pea()
{
}


std::string Pea::serialize()
{
	using namespace std;

	string s = "Pea\n";

	s += to_string(this->rowUp);
	s += " ";
	s += to_string(this->colLeft);
	s += " ";
	s += to_string(this->isColliding);
	s += "\n";

	return s;
}