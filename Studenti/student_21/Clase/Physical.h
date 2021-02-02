#pragma once
#include "DrawableObject.h"
#include "Collider.h"
class Physical :
	public DrawableObject
{
public:
	enum class Type {
		LIFEFORM
	};
private:
	Type _type;
	Collider<Physical> collider;
	std::list<Physical*>& groupBoundTo;
public:
	Physical(std::list<Physical*>& groupBoundTo, 
		std::string sprite_file,
		C2D::Vector2 position, 
		const std::list<Physical*>& everyPhysicalObject,
		int updateReference);
	Physical() = delete;
	Physical(const Physical&) = delete;
	Physical& operator= (const Physical&) = delete;
	virtual ~Physical() 
	{
		removeSelfFromGroup();
	}

	Type& getType() { return _type; }

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;

	virtual void onCollide(Physical&) = 0; 
private:
	void removeSelfFromGroup();
};

