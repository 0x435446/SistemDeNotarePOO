#include "PeaShooter.h"
#include "Zombie.h"


PeaShooter::PeaShooter(int x, int y, std::string &&glyph) : Entity(x, y, glyph)
{
	movement = 0;
	if (glyph.find("sun") != std::string::npos) {
		special = true;
	}
}


PeaShooter::~PeaShooter()
{
}

void PeaShooter::interactWith(Zombie & e)
{
	std::string delGl = "";
	for (int i = 1; i <= glyph.size(); i++)
		delGl += " ";
	glyph = delGl;
	outFile << "Zombie attack a plant\n";
	//e.hp--; 
}

void PeaShooter::interactWith(PeaShooter & e)
{
	outFile << "PeaShooter with PeaShooter\n";
}

void PeaShooter::interactWith(Pea & e)
{
	outFile << "PeaShooter with Pea\n";
}

void PeaShooter::interact(Entity & e)
{
	e.interactWith(*this);
}

bool PeaShooter::getSpecial()
{
	bool copy = special;
	special = false;
	return copy;
}


