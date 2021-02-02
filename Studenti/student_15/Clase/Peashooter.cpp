#include "Peashooter.h"
#include <string>
#include <time.h>
#include <chrono>
#include "ConsoleOutput.h"

using namespace std;

Peashooter::Peashooter(int damage, string name, char alias, int first, int second, int life, int cost = 1, int on_battle = 0) : Flower(name, alias, first, second, life, cost, on_battle) {
	this->damage = damage;
}

void Peashooter::action() {
	if (attack_pos.second == 150) {
		attack_pos.second = this->get_position().second + 6;
		UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
		out(this->get_position().first, 150) << " ";
	} else 
		attack_pos.second += 6;
	
};