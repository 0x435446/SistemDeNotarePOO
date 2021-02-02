#pragma once
#include "Entity.h"
class Score : public Entity
{ //20,7
private:
	int value ;
	Score();
	
public:
	int getvalue();
	static Score*instance;
	void plus(int x);
	void minus(int x);
	static Score* getinstance();
	~Score();
	void draw();
	void uppdate(std::string);
};

