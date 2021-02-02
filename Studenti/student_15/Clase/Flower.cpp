#include <string>
#include "Flower.h"
#include "ConsoleOutput.h"

using namespace std;


Flower::Flower(string name, char alias, int first, int second, int life, int cost, bool on_battle) {
	this->position.first = first;
	this->position.second = second;
	this->alias = alias;
	this->name = name;
	this->life = life;
	this->cost = cost;
	this->on_battle = on_battle;
}

void Flower::action() {};
string Flower::getname() {
	return name;
}
char Flower::getalias() {
	return alias;
}

void Flower::draw() {
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	out(position.first, position.second) << alias;
}

int Flower::getCost()
{
	return this->cost;
}

void Flower::change_vect_pos(int vect_pos) {
	this->vect_pos = vect_pos;
}

int Flower::get_vect_pos() {
	return vect_pos;
}

void Flower::changealias(char alias) {
	this->alias = alias;
}

void Flower::change_position(int first, int second) {
	position.first = first;
	position.second = second;
}

pair<int, int> Flower::get_position(){
	return this->position;
}

void Flower::change_on_battle() {
	this->on_battle = !this->on_battle;
}

int Flower::get_on_battle() {
	return on_battle;
}