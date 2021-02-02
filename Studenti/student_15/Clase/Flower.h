#pragma once
#include <string>
#include <utility>

using namespace std;

class Flower {
private:
	string name;
	char alias;
	int on_battle;
	int life;
	pair<int, int> position;
	int cost;

public:
	int vect_pos;
	Flower(string, char, int, int, int, int, bool);
	~Flower() = default;
	void action();
	char getalias();
	void changealias(char);
	void draw();
	int getCost();
	void change_position(int first, int second);
	string getname();
	void change_vect_pos(int);
	pair<int, int> get_position();
	int get_vect_pos();
	void change_on_battle();
	int get_on_battle();
};
