#pragma once
#include "Zombie.h"
class BucketHead final : public Zombie
{
public:
	BucketHead(const unsigned int&, const unsigned int&, char c);
	void attack() override;
	~BucketHead();
};

