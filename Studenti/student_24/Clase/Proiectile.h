#pragma once
class Proiectile
{private:
	int x, y;
	int damage;
public:
	Proiectile(int a, int b);
	void go();
	Proiectile();
	~Proiectile();
};

