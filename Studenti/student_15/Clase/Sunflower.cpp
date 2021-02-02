#include "Sunflower.h"
#include <string>

using namespace std;


Sunflower::Sunflower(string name, char alias, int first, int second, int life, int cost = 2, int on_battle = 0) : Flower(name, alias, first, second, life, cost, on_battle) {};

void Sunflower::action() {}
