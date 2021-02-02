#include "ResourceFactory.h"
#include "Exception.h"
#include <stdlib.h>
#include <time.h>   

ResourceFactory* ResourceFactory::s_instance = nullptr;

ResourceFactory* ResourceFactory::GetInstance()
{
	if (ResourceFactory::s_instance == nullptr)
		ResourceFactory::s_instance = new ResourceFactory();
	return ResourceFactory::s_instance;
}

void ResourceFactory::DeleteInstance(ResourceFactory* instance)
{
	if (ResourceFactory::s_instance != nullptr)
	{
		delete instance;
		ResourceFactory::s_instance = nullptr;
	}
}

Resource* ResourceFactory::CreateResource()
{
	ResourceType type = ResourceType(rand() % 1 + 1);
	srand(time(NULL));
	int place = rand() % 9 + 1;
	switch (type)
	{
	case SunType:
		return new Sun(1, (place*16 + 1));
		break;
	default:
		throw Exception("No valid resource type");
		break;
	}
}

ResourceFactory::ResourceFactory()
{
}

ResourceFactory::~ResourceFactory()
{
}