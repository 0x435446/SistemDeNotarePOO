#include "CherryBomb.h"
CherryBomb::CherryBomb(const int& row, const int& col) :Plant(row, col, "CB", 9999, 9999,150) {
	this->nextThrow = time(nullptr) + atackSpeed;
}
CherryBomb::CherryBomb() : Plant(0, 0, "CB", 9999,9999, 150) {
	this->nextThrow = time(nullptr) + atackSpeed;
}