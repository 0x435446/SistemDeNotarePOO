#pragma once
#include <string>

#define FRAMES_PER_SECOND 60  //// NOT TO CHANGE!!!!!!!!!

class Object
{
public:
	Object() {}
	virtual ~Object() {}

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;
};