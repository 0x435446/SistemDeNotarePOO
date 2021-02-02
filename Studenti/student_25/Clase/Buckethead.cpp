#include "Buckethead.h"



Buckethead::Buckethead(Casuta* c) : Zombie(c)
{
	this->c = 'B';
	this->hp = 10;
	this->damage = 1;
}


Buckethead::~Buckethead()
{
}