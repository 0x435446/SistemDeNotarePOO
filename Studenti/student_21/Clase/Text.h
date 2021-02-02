#pragma once
#include "GameObject.h"
#include "NextLevelConsoleHandler.h"
#include "Renderer.h"
class Text :
	public GameObject
{
	ConsoleHandlerV2& localHandler = ConsoleHandlerV2::getInstance();
	Transform transform;
	Sprite sprite;
	Renderer renderer;
public:
	Text(std::string content, const Transform& parentTransform) :
		transform(parentTransform.getPosition().getX() + (parentTransform.getSize().getX() - content.length()) / 2,
			parentTransform.getPosition().getY() - 1,
			content.length(), 1),
		sprite(1, content),
		renderer(transform, sprite) 
	{
		AddComponent<Transform>(&transform);
		AddComponent<Sprite>(&sprite);
		AddComponent<Renderer>(&renderer);
	}
	Text() = delete;
	Text(const Text&) = delete;
	Text& operator=(const Text&) = delete;
	~Text()
	{
		GameObject::End();
	}
	void Update() override final
	{
		GameObject::Update();
	}
	void Start() override final
	{
		GameObject::Start();
	}
};

