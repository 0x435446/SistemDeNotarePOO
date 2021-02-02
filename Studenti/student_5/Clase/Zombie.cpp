#include "Zombie.h"
#include "PeaShooter.h"
#include "Pea.h"

Zombie::Zombie(int x, int y, int hp) : Entity(x, y, "")
{
	movement = -1;
	this->hp = hp;
	if (hp == 2)
		glyph = "zombie";
	else if (hp == 4)
		glyph = "buckzombie";
}


Zombie::~Zombie()
{
}

void Zombie::interactWith(Zombie & e)
{
	outFile << "zombie with zombie";
}

void Zombie::interactWith(PeaShooter & e)
{
	outFile << "from zombie, zombie wiht peashooter\n";
}

void Zombie::interactWith(Pea & e)
{
	outFile << "zombie got hit by a pea\n";
	hp--;
	if (hp <= 0) {
		std::string delGl("");
		for (int i = 1; i <= glyph.size(); i++)
			delGl += " ";
		glyph = delGl;
	}
	e.setGlyph(" ");
}

void Zombie::interact(Entity & e)
{
	e.interactWith(*this);
}
