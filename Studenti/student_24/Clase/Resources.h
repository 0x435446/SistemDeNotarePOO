#pragma once
#include "Entity.h"
#include <vector>
#include "Resources_Zone.h"

class Resources :
	public Entity
{
private :
	Resources();
	int x, y;
	int frecv;
	std::vector<Resources_Zone*> zone;
public:
	static Resources* instance;
	static Resources * getinstance();
	void set(int a,int b);
	void lowfrecv(int x);
	bool isfull();
	
	~Resources();
	void draw();
	void uppdate(std::string);
};

