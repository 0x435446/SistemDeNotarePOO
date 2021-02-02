#pragma once
#include "InteractableObject.h"
#include "Text.h"
class Button:
	public InteractableObject
{
	Text textContent;
public:
	Button(std::list<InteractableObject*>& groupBoundTo,
		C2D::Vector2 position,
		std::string stringContent) :
		InteractableObject(groupBoundTo, "Sprites/ButtonFrame.sprite", position),
		textContent(stringContent, _transform()){}
	Button() = delete;
	Button(const Button&) = delete;
	Button& operator= (const Button&) = delete;
	virtual ~Button() {}


	virtual void Update()
	{
		GameObject::Update();
		textContent.Update();
	}
	virtual void Start()
	{
		GameObject::Start();
		textContent.Start();
	}

	virtual void End()
	{
		GameObject::End();
	}

	virtual void onMouseHover()
	{
		_sprite().setColor(14);
	}
	virtual void onMouseClick()
	{
		_sprite().setColor(10);
	}
	virtual void onMouseDoubleClick() {}
	virtual void tryReset()
	{
		_sprite().resetColor();
	}
	virtual void onClickOutOfRange() {}
};

