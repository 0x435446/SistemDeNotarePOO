#include "Zombie.h"
time_t Zombie::nextZombie = time(nullptr) + Zombie::period;
Zombie::Zombie(const unsigned& row, const unsigned& col, const std::string& shape, const unsigned& speed,const unsigned& health) :
	Drowable(row, col, shape), speed(speed),health(health) {
	this->nextMove = time(nullptr) + this->speed;
}
void Zombie::printEntity()const {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(6 * this->row + 5, 17 * this->col + 11) << this->shape;
}
void Zombie::clearEntity()const {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(6 * this->row + 5, 17 * this->col + 11) << "        ";
}
//void Zombie::move() {
//	if (this->nextMove < time(nullptr)) {
//		this->clearEntity();
//		this->col--;
//		this->printEntity();
//		this->nextMove = time(nullptr) + this->speed;
//	}
//}