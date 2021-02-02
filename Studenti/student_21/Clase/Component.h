#pragma once
#include "Object.h"

//template <class CustomType>
class Component :
	public Object
{
	const int updateReference;
	const int offset;
	bool ready;
	int calls;
public:
	enum class Type {
		SPRITE, RENDERER, TRANSFORM, COLLIDER, MOVER, INPUTPROCESSER, BIOLOGICAL, WEAPON   // not the cleanest, but it's OK
	};
private:
//	static std::string _desc;
	const Type type;
	const bool isRemovable;
public:
	Component() = delete;
	Component(Type type,
		int updateReference) : 
		type(type), 
		isRemovable(false),
		ready(true),
		calls(0),
		updateReference(updateReference),
		offset(updateReference == 0 ? 1 : FRAMES_PER_SECOND / updateReference) {} // ???
	Component(Type type, 
		int updateReference,
		const bool isRemovable) : 
		type(type), 
		isRemovable(isRemovable),
		ready(true),
		calls(0),
		updateReference(updateReference),
		offset(updateReference == 0 ? 1 : FRAMES_PER_SECOND / updateReference) {}
	Component(const Component&) = delete;

	bool operator == (const Component& component) const { return type == component.type; }
	bool operator != (const Component& component) const { return !operator==(component); }

	virtual ~Component() {}

	void CallUpdate()
	{
		++calls;
		if (ready)
		{
			ready = false;
			Update();
		}
		if (calls == offset)
		{
			ready = true;
			calls = 0;
		}
	}
	void CallStart()
	{
		Start();
	}
	void CallEnd()
	{
		End();
	}

	Type getType() { return type; }

private:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;
};