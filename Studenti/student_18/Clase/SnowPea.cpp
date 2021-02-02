#include "SnowPea.h"
SnowPea::SnowPea(const int& row, const int& col) :Plant(row, col, "SPea",1,20,175) {
	this->nextThrow = time(nullptr) + atackSpeed;
}
SnowPea::SnowPea() : Plant(0, 0, "PShot", 1, 20, 175) {
	this->nextThrow = time(nullptr) + atackSpeed;
}
