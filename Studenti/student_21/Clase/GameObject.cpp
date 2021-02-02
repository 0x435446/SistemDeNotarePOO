#include "GameObject.h"
#include <iostream>

void GameObject::Start()
{
	StartComponents();
}
void GameObject::Update()
{
	UpdateComponents();
	if (_self_destruct)
	{
		GameObject::End();
		delete this;
	}
}
void GameObject::End()
{
	EndComponents();
}

void GameObject::UpdateComponents()
{
	for (Component* i : components)
		i->CallUpdate();
}
void GameObject::StartComponents()
{
	for (Component* i : components)
		i->CallStart();
}
void GameObject::EndComponents()
{
	for (Component* i : components)
		i->CallEnd();
}