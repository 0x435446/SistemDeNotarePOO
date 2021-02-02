#include "WallNut.h"
WallNut::WallNut(const int& row, const int& col) :Plant(row, col, "WNut",9999,9999,50) {
	this->nextThrow = time(nullptr) + atackSpeed;
}
WallNut::WallNut() : Plant(0, 0, "WNut",9999,9999,50) {
	this->nextThrow = time(nullptr) + atackSpeed;
}