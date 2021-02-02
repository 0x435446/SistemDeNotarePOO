#include "SunFlower.h"
SunFlower::SunFlower(const int& row, const int& col) :Plant(row, col,"SF",999,10,50) {
	this->nextThrow = time(nullptr) + atackSpeed;
}
SunFlower::SunFlower() : Plant(0, 0, "SF", 999, 10, 50) {
	this->nextThrow = time(nullptr) + atackSpeed;
}