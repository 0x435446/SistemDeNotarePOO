#pragma once
#include <list>
#include "Component.h"
class GameObject :
	public Object
{
	std::list<Component*> components;
	bool _self_destruct;
public:
	GameObject() : _self_destruct(false)
	{
		Start();
	}
	GameObject(const GameObject&) = delete;
	GameObject& operator= (const GameObject&) = delete;
	virtual ~GameObject() {}

	virtual void Start() override;
	virtual void Update() override; ///////////////// YOU MUST CALL THIS EVERY FRAME !!!!
	virtual void End() override;

	template <class myType>
	void AddComponent(myType* component)
	{
		for (Component* i : components)
		{
			if (component->getType() == i->getType())
				return;
			////// SHOULD BE EXCEPTION
		}
		components.push_back(component);
	}
	template <class myType>
	void AddComponentWithPriority(myType* component)
	{
		for (Component* i : components)
		{
			if (component->getType() == i->getType())
				return;
			////// SHOULD BE EXCEPTION
		}
		components.push_front(component);
	}
	template <class myType, Component::Type type>
	void AddComponentWithBind(myType* component)
	{
		// insert after specific component, not needed now
	}
	template <Component::Type type>
	void RemoveComponent()
	{
		for (Component* i : components)
		{
			if (i->getType() == type)
			{
				components.remove(i);
				return;
			}
		}
		//// EXCEPTION
	}
	template <Component::Type type>
	Component& GetComponent()
	{
		for (Component* i : components)
		{
			if (i->getType() == type)
			{
				return *i;
			}
		}
		//// EXCEPTION
	}

	void _mark_for_death()
	{
		_self_destruct = true;
	}
	bool _is_dead() /// need rework
	{
		return _self_destruct;
	}


private:
	void UpdateComponents();
	void StartComponents();
	void EndComponents();
};

