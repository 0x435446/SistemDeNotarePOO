#pragma once

class Resurse
{
protected:
	int val;
public:
	Resurse();
	~Resurse();

	void set_val(int val) { this->val = val; }
	int get_val() { return this->val; }

};

