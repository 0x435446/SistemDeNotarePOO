#include "Sun.h"



Sun::Sun(int x, int y) : Entity(x, y, "sun")
{
}

Sun::~Sun()
{
}

void Sun::interactWith(Zombie & e)
{
}

void Sun::interactWith(PeaShooter & e)
{
}

void Sun::interactWith(Pea & e)
{
}

void Sun::interact(Entity & e)
{
}
