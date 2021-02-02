#include "Peashooter.h"
Peashooter::Peashooter(const int& row, const int& col) :Plant(row,col,"PShot",1,20,100) {
	this->nextThrow=time(nullptr) + atackSpeed;
}
Peashooter::Peashooter() : Plant(0, 0, "PShot", 1, 20, 100) {
	this->nextThrow = time(nullptr) + atackSpeed;
}
