#pragma once
#include "IDrawable.h"
#include <fstream>
typedef struct user
{
	std::string name;
	int score;
};
class Scoreboard:public IDrawable
{
public:
	static Scoreboard& getInstance();
	~Scoreboard() { ; }
	void draw();
	void modifyCount(int);
	int getMaxScore();
	void updateScore(std::string);
private:
	static Scoreboard* instance;
	bool blinked;
	Scoreboard();
	int count;
};

