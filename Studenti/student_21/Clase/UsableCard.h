#pragma once
#include "InteractableObject.h"
#include "UserData.h"
#include "NextLevelConsoleHandler.h"
//#include "ConsoleHandler.h"
class UsableCard :
	public InteractableObject
{
	ConsoleHandlerV2& _cns_access = ConsoleHandlerV2::getInstance();
	Renderer* __content_private_renderer_access;							 // /
	MouseHandler& __useless_lame_mouse_handler = MouseHandler::getInstance();// if u see this, lemme tell you ik it's rly stupid
	Transform* __content_private_transform_access;							 // \ 
	GameObject content;
	C2D::Vector2 default_content_position;
	UserData& localData = UserData::getInstance();
protected:
	bool is_selected;
	int price;
public:
	UsableCard(std::list<InteractableObject*>& groupBoundTo, std::string sprite_file, C2D::Vector2 position, std::string content_sprite_file, int price);
	UsableCard() = delete;
	UsableCard(const UsableCard&) = delete;
	UsableCard& operator= (const UsableCard&) = delete;
	virtual ~UsableCard()
	{
		content.End();
		delete &(content.GetComponent<Component::Type::RENDERER>());
		delete &(content.GetComponent<Component::Type::TRANSFORM>());
		delete &(content.GetComponent<Component::Type::SPRITE>());
		GameObject::End();
	}

	virtual void Start() override {
		GameObject::Start();
		content.Start();
	}
	virtual void Update() override {
		GameObject::Update();
		if (is_selected)
		{
			auto lf = [&]() {
				C2D::Vector2 newPosition = C2D::Vector2(__useless_lame_mouse_handler.getPosX(), __useless_lame_mouse_handler.getPosY());
				if (newPosition.getX() >= 15 && newPosition.getX() < 150 && newPosition.getY() < 40)
				{
					newPosition.snapToGrid();
					__content_private_transform_access->setPosition(newPosition);
					content.Update();
				}};
			lf();
		}
		content.Update();
		__content_private_transform_access->setPosition(default_content_position);
		__content_private_renderer_access->CallUpdate();

	}
	virtual void End() override { GameObject::End(); }

	virtual void onMouseHover() override final
	{
		if (!is_selected && localData.getInGameCurrency() >= price)
			_sprite().setColor(14);
	}
	virtual void onMouseClick() override final
	{
		if (!is_selected && localData.getInGameCurrency() >= price)
		{
			_sprite().setColor(10);
			is_selected = true;
		}
		else
		{
			resetSelect();
		}
	}
	virtual void onMouseDoubleClick() {}
	virtual void tryReset() final
	{
		if (!is_selected)
			_sprite().resetColor();
	}
	virtual void resetSelect() final
	{
		_sprite().resetColor();
		is_selected = false;
	}
	virtual void onClickOutOfRange()
	{
		resetSelect();
	}

protected:

	template <class myType>
	bool checkTile(C2D::Vector2 posToCheck,std::list<myType*>& listToCheck)
	{
		typename std::list<myType*>::iterator prev;
		for (auto i = listToCheck.begin(); i != listToCheck.end();)
		{
			prev = i++;
			if ((posToCheck.getX() == (*prev)->_transform().getPosition().getX()) &&
				(posToCheck.getY() == (*prev)->_transform().getPosition().getY()))
				return false;
		}
		return true;
	}
	void buy()
	{
		localData._getInGameCurrency() -= price;
	}
private:
	void printPrice()
	{
	}

};

