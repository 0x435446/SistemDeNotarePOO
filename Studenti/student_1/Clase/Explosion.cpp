#include "Explosion.h"

using namespace GameMechanics;

Explosion::Explosion(int rowUp, int colLeft) :Projectile(rowUp, colLeft)
{
	this->ID = EntityID::EXPLOSION;

	auto index = getIndex(PROJECTILES_ID, this->ID);

	this->damage = PROJECTILES_DAMAGE[index];
	this->inflictableEffect = EffectInflicted::NONE;
	this->speed = PROJECTILES_SPEED[index];

	this->width = UserInterface::EXPLOSION_WIDTH;
}


Explosion::~Explosion()
{
}

std::string Explosion::serialize()
{
	using namespace std;

	string s = "Explosion\n";

	s += to_string(this->rowUp);
	s += " ";
	s += to_string(this->colLeft);
	s += " ";
	s += to_string(this->isColliding);
	s += "\n";

	return s;
}

