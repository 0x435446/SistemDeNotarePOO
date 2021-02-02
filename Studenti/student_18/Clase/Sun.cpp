#include "Sun.h"
unsigned Sun::period = 5;
time_t Sun::nextSun = time(nullptr) + Sun::period;
Sun::Sun(const unsigned& row, const unsigned& col) :Resources(row, col, "SUN", 50) {}