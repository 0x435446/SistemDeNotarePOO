#include "Resources.h"
Resources::Resources(const unsigned& row, const unsigned& col, const std::string& shape, const unsigned& reward) :
	Drowable(row, col, shape), reward(reward){}
void Resources::printEntity()const {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(6 * this->row + 5, 17 * this->col + 9) << this->shape;
}
void Resources::clearEntity()const {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(6 * this->row + 5, 17 * this->col + 9) << "   ";
}