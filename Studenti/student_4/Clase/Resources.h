#pragma once
class Resources
{
protected:
	Resources(int Valoare);
	int Valoare;
public:
	virtual int Give_Resource() = 0;
};
