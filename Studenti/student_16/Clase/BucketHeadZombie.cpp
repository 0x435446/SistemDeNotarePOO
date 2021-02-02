#include "BucketHeadZombie.h"
BucketHeadZombie::BucketHeadZombie(int sX, int sY)
	:Zombie(sX, sY,"BucketHeadZombie") 
{
}
void BucketHeadZombie::draw()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	std::ifstream fin("bucketheadzombie.txt");
	int j = 1;
	char buff[1024];
	while (!fin.eof())
	{
		fin.getline(buff, 1024);
		conOut(this->startX + j, this->startY) << buff;
		j++;
	}
	fin.close();
	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 250)
	{
		begin = end;
		conOut(this->startX + 1, this->startY + 1) << " ";
		conOut(this->startX + 2, this->startY + 2) << " ";
		conOut(this->startX + 3, this->startY + 2) << " ";
		conOut(this->startX + 4, this->startY + 3) << " ";
		this->startY -= 1;
	}
}
void BucketHeadZombie::executeFunction()
{
	;
}
