#include "Entity.h"
#include "Sun.h"
#include "ConsoleOutput.h"


#define BASIC_HEALTH 100
#define BASIC_ATTACK 30
#define PROJECTILE_X 23
#define PROJECTILE_Y 17
#define MULTY 12
#define ZOMBIE_SPEED 3


Entity::Entity()
{
	this->type = "default";
	
}

Entity::~Entity()
{
}

Pea::Pea()
{
	this->health = BASIC_HEALTH + 50;
	this->damage = BASIC_ATTACK;
	this->type = "Pea";

}
Pea::~Pea()
{
}
void Pea::attack()
{





}

Sunflower::Sunflower()
{
	Sun &sun_generator = Sun::getInstance();
	sun_generator.buy_sunflower();

	this->health = BASIC_HEALTH;
	this->damage = 0;
	this->type = "Sunflower";
}

Sunflower::~Sunflower()
{
}

void Sunflower::attack()
{
}


Cherry::Cherry()
{
	this->health = BASIC_HEALTH - 50;
	this->damage = BASIC_ATTACK*5;
	this->type = "Cherry";
}

Cherry::~Cherry()
{
}

void Cherry::attack()
{


}

Wallnut::Wallnut()
{
	this->health = BASIC_HEALTH * 2 + 50;
	this->damage = 0;
	this->type = "Wallnut";
}

Wallnut::~Wallnut()
{
}

void Wallnut::attack()
{
}


Snowpea::Snowpea()
{
	this->health = BASIC_HEALTH + 50;
	this->damage = BASIC_ATTACK - 10;
	this->type = "Snowpea";
}

Snowpea::~Snowpea()
{
}

void Snowpea::attack()
{


}

Zombie::Zombie()
{
	this->health = BASIC_HEALTH ;
	this->damage = BASIC_ATTACK +20;
	this->speed = ZOMBIE_SPEED;
	this->type = "Zombie";
}

Zombie::~Zombie()
{
}

void Zombie::attack()
{
}


Zombie_bucket::Zombie_bucket()
{
	this->health = BASIC_HEALTH * 2 + 50;
	this->damage = BASIC_ATTACK + 20;
	this->speed = ZOMBIE_SPEED + 2;
	this->type = "Bucket";
}

Zombie_bucket::~Zombie_bucket()
{
}

void Zombie_bucket::attack()
{
}

void PeaProjectile::attack()
{
}
PeaProjectile::PeaProjectile()
{
	this->health = BASIC_HEALTH * 2 + 50;
	this->damage = BASIC_ATTACK;
	this->type = "projectile";


}

PeaProjectile::~PeaProjectile()
{
}
