#pragma once
#include "Sun.h"

class ResourceFactory
{
public:
	static ResourceFactory* GetInstance();
	static void DeleteInstance(ResourceFactory* instance);
	static Resource* CreateResource();
private:
	static ResourceFactory* s_instance;
	ResourceFactory();
	~ResourceFactory();
};