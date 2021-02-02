#pragma once
#include "Entity.h"
#include "Sun.h"
class Resources_Zone : Entity
{
private:
	int x, y;
	bool filled;
	Sun* sun;
public:
	void freee();
	void setfilled();
	void setfree();
	bool isfilled();
	Resources_Zone();
	~Resources_Zone();
	Resources_Zone(int a,int b );
	void draw();
	void set_sun(Sun* sun);
	bool selected(std::string);
	void uppdate(std::string);



};

