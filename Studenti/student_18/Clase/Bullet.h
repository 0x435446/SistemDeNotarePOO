#pragma once
#include"Drowable.h"
class Bullet:public Drowable{
private:
	bool alive;
public:
	Bullet(const int&row, const int&col,const std::string&shape);
	virtual ~Bullet() {}
};

