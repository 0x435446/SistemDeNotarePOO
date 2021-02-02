#include "FrozenPea.h"

using namespace GameMechanics;

FrozenPea::FrozenPea(int rowUp, int colLeft) :Projectile(rowUp, colLeft)
{
	this->ID = EntityID::FROZENPEA;

	auto index = getIndex(PROJECTILES_ID, this->ID);

	this->damage = PROJECTILES_DAMAGE[index];
	this->inflictableEffect = EffectInflicted::FROZEN;
	this->speed = PROJECTILES_SPEED[index];

	this->width = UserInterface::PEA_WIDTH;
}


FrozenPea::~FrozenPea()
{
}

std::string FrozenPea::serialize()
{
	using namespace std;

	string s = "FrozenPea\n";

	s += to_string(this->rowUp);
	s += " ";
	s += to_string(this->colLeft);
	s += " ";
	s += to_string(this->isColliding);
	s += "\n";

	return s;
}

