#pragma once
#include "Transform.h"
#include "Sprite.h"
#include "MouseHandler.h"

#define MOUSE_CLICK 0
#define MOUSE_MOVE 1
#define MOUSE_DOUBLE_CLICK 2

template <class Interactable>
class InputProcesser :
	public Component
{
	MouseHandler& localMouseHandler;
	Interactable& parent;
	const Transform& parentTransform;
public:
	InputProcesser() = delete;
	InputProcesser(const InputProcesser&) = delete;
	InputProcesser& operator=(const InputProcesser&) = delete;
	InputProcesser(Interactable& parent) :
		Component(Component::Type::INPUTPROCESSER, 0),
		parent(parent),
		parentTransform(parent._transform()),
		localMouseHandler(MouseHandler::getInstance()) {}
	InputProcesser(Interactable& parent,
		bool isRemovable) :
		Component(Component::Type::INPUTPROCESSER, isRemovable, 0),
		parent(parent),
		parentTransform(parent._transform()),
		localMouseHandler(MouseHandler::getInstance()) {}
	~InputProcesser() 
	{
		localMouseHandler.releaseInstance();
	}

	C2D::Vector2 getMousePosition()
	{
		return C2D::Vector2(localMouseHandler.getPosX(), localMouseHandler.getPosY());
	}

private:
	void Start() override final {}

	void Update() override final
	{
		processMouseInput();
	}
	void End() override final {}


	void processMouseInput()
	{
		int result = localMouseHandler.getProcessedInput();
		switch (result)
		{
		case MOUSE_CLICK:
		{
			if (isMouseInRange())
				parent.onMouseClick();
			else
				parent.onClickOutOfRange();
			break;
		}
		case MOUSE_MOVED:
		{
			if (isMouseInRange())
				parent.onMouseHover();
			else
				parent.tryReset();
			break;
		}
		case MOUSE_DOUBLE_CLICK:
		{
			if (isMouseInRange())
				parent.onMouseDoubleClick();
			break;
		}
		default:
		{
			break;
		}
		}
			
	}

	bool isMouseInRange()
	{
		int mousePosX = localMouseHandler.getPosX();
		int mousePosY = localMouseHandler.getPosY();
		int thisPosX = parentTransform.getPosition().getX();
		int thisPosY = parentTransform.getPosition().getY();
		int thisWidth = parentTransform.getSize().getX();
		int thisHeight = parentTransform.getSize().getY();
		if (mousePosX < thisPosX)
			return false;
		if (mousePosY > thisPosY)
			return false;
		if (mousePosX >= thisPosX + thisWidth)
			return false;
		if (mousePosY <= thisPosY - thisHeight)
			return false;
		return true;
	}
};



