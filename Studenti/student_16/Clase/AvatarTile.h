#pragma once
#include "IDrawable.h"
#include "Avatar.h"
class AvatarTile:public IDrawable
{
public:
	AvatarTile(int, int);
	~AvatarTile() { ; }
	void addAvatar(Avatar* p) { plant = p; occupied = true; }
	void removeAvatar() { delete plant; plant = nullptr; occupied = false; }
	void draw();
	Avatar* getAvatar() { return plant; }
	bool isOccupied() { return occupied; }
	int getX() const { return startX; }
	int getY() const { return startY; }
private:
	bool occupied;
	Avatar* plant;
};

