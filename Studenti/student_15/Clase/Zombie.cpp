#include "Zombie.h"
#include "ConsoleOutput.h"


Zombie::Zombie(int first, int second, int life, char alias) {
	z_position.first = first;
	z_position.second = second;
	this->life = life;
	this->alias = alias;

}

pair<int, int> Zombie::get_position() {
	return z_position;
}

void Zombie::damage(pair<int, int> pos) {
	if (pos.first - 2 < z_position.first && pos.first + 2 > z_position.first)
		if (pos.second >= z_position.second)
			life--;
	if (life == 0)
		alias = ' ';
}

void Zombie::draw() {
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	out(z_position.first, z_position.second) << alias;
}

int Zombie::dead() {
	return !life;
}