#include "Proiectile.h"
#include<time.h>
#include<chrono>

using namespace std::chrono;


Proiectile::Proiectile()
{
}

Proiectile::Proiectile(int a, int b)
{
	x = a; y = b;
}

Proiectile::~Proiectile()
{
}
