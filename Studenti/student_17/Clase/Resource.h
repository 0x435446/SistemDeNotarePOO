#pragma once
#include "DisplayableEntity.h"

enum ResourceType
{
	NoResourceType = 0, SunType
};

class Resource : public DisplayableEntity
{
public:
	Resource();
	virtual ~Resource();
	ResourceType GetType() const;
	int GetValue() const;
protected:
	void SetType(const ResourceType type);
	void SetValue(const int value);
private:
	static unsigned int s_resourcesIdCounter;
	unsigned int m_resourceId;
	ResourceType m_type;
	int m_value;
};