#pragma once
#include <utility>

using namespace std;


class Zombie
{
public:
	Zombie(int, int, int, char);
	~Zombie() = default;
	pair<int, int> get_position();
	void damage(pair<int, int>);
	void draw();
	int dead();

private:
	pair<int, int> z_position;
	int life;
	char alias;


};

