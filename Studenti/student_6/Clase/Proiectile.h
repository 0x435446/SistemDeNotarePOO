#pragma once

class Proiectile
{
protected:
	int putere;
public:
	Proiectile(int);
	~Proiectile();

	virtual void ataca(int,int)=0;
};

