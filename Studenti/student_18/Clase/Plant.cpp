#include "Plant.h"
Plant::Plant(const unsigned& row, const unsigned& col, const std::string& shape, const unsigned& atackSpeed, const unsigned& health,const unsigned&price) :
Drowable(row, col, shape), atackSpeed(atackSpeed), health(health),nextThrow(time(nullptr)+atackSpeed),price(price) {}
void Plant::printEntity()const {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(6 * this->row + 5, 17 * this->col + 2) << this->shape;
}
void Plant::clearEntity()const {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(6 * this->row + 5, 17 * this->col + 2) << "     ";
}