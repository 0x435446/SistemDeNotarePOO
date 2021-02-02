#include "Resource.h"

unsigned int Resource::s_resourcesIdCounter = 0;

Resource::Resource() : m_resourceId(Resource::s_resourcesIdCounter), m_type(NoResourceType), m_value(0)
{
	Resource::s_resourcesIdCounter++;
}

Resource::~Resource()
{
}

ResourceType Resource::GetType() const
{
	return this->m_type;
}

int Resource::GetValue() const
{
	return this->m_value;
}

void Resource::SetType(const ResourceType type)
{
	this->m_type = type;
}

void Resource::SetValue(const int value)
{
	this->m_value = value;
}