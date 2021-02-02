#pragma once
#include "DrawableObject.h"
#include "InputProcesser.h"
class InteractableObject :
	public DrawableObject
{
	std::list<InteractableObject*>& groupBoundTo;
	InputProcesser<InteractableObject> inputProcesser;
public:
	InteractableObject(std::list<InteractableObject*>& groupBoundTo, std::string sprite_file, C2D::Vector2 position);
	InteractableObject() = delete;
	InteractableObject(const InteractableObject&) = delete;
	InteractableObject& operator= (const InteractableObject&) = delete;
	virtual ~InteractableObject()
	{
		_remove_self_from_group();
	}

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;

	virtual void onMouseHover() = 0;
	virtual void onMouseClick() = 0;
	virtual void onMouseDoubleClick() = 0;
	virtual void tryReset() = 0;
	virtual void onClickOutOfRange() = 0;
	C2D::Vector2 _get_mouse_position()
	{
		return inputProcesser.getMousePosition();
	}
private:
	void _remove_self_from_group()
	{
		groupBoundTo.remove(this);
	}
};

