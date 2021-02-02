#pragma once
#include "Scene.h"
#include "NextLevelConsoleHandler.h"
#include "MouseHandler.h"
#include "GameManager.h"
#include "UIObjects.h"

enum class UIPrefabs {
	_Null,
	_Exit,
	_Reset,
	PlayButton,
	ExitButton,
	MenuScene,
	GameScene
};

template <UIPrefabs mainType, UIPrefabs secondaryType = UIPrefabs::_Null>
class UIPrefab {};

class SceneManager
{
	static SceneManager* _instance;
	static int _instanceCount;
	static Scene* currentScene;
	static Scene* nextScene;
	ConsoleHandlerV2& localHandler = ConsoleHandlerV2::getInstance();
	MouseHandler& localMHandler = MouseHandler::getInstance();
public:
	static SceneManager& getInstance();
	static void releaseInstance();

	SceneManager(const SceneManager&) = delete;
	SceneManager(SceneManager&&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	SceneManager& operator=(SceneManager&&) = delete;

	bool Run()
	{
		if (!loadScene())
			return false;
		currentScene->Init();
		currentScene->Run();
		currentScene->Stop();
	}
	static void setNextScene(Scene* newScene)
	{
		nextScene = newScene;
	}

private:
	SceneManager();
	~SceneManager();
	void Init();
	void unloadScene()
	{
		delete currentScene;
		currentScene = nullptr;
	}
	bool loadScene()
	{
		if (nextScene == nullptr)
		{
			unloadScene();
			return false;
		}
		if (currentScene != nullptr)
		{
			currentScene->Stop();
			unloadScene();
		}
		currentScene = nextScene;
		return true;
	}
};

static void HandleScenes();
static UIPrefabs nextScene = UIPrefabs::_Null;

template<>
class UIPrefab<UIPrefabs::PlayButton, UIPrefabs::MenuScene> :
	public Button
{
public:
	UIPrefab(std::list<InteractableObject*>& groupBoundTo,
		C2D::Vector2 position) :
		Button(groupBoundTo, position, "PLAY DEMO") {}
	UIPrefab() = delete;
	UIPrefab(const UIPrefab&) = delete;
	UIPrefab& operator= (const UIPrefab&) = delete;
	virtual ~UIPrefab() {}
	virtual void onMouseClick() override final
	{
		Button::onMouseClick();
		nextScene = UIPrefabs::GameScene;
		HandleScenes();
	}

};

template<>
class UIPrefab<UIPrefabs::ExitButton, UIPrefabs::MenuScene> :
	public Button
{
public:
	UIPrefab(std::list<InteractableObject*>& groupBoundTo,
		C2D::Vector2 position) :
		Button(groupBoundTo, position, "EXIT") {}
	UIPrefab() = delete;
	UIPrefab(const UIPrefab&) = delete;
	UIPrefab& operator= (const UIPrefab&) = delete;
	virtual ~UIPrefab() {}
	virtual void onMouseClick() override final
	{
		Button::onMouseClick();
		nextScene = UIPrefabs::_Exit;
		HandleScenes();
	}
};

template<>
class UIPrefab<UIPrefabs::ExitButton, UIPrefabs::GameScene> :
	public Button
{
public:
	UIPrefab(std::list<InteractableObject*>& groupBoundTo,
		C2D::Vector2 position) :
		Button(groupBoundTo, position, "EXIT") {}
	UIPrefab() = delete;
	UIPrefab(const UIPrefab&) = delete;
	UIPrefab& operator= (const UIPrefab&) = delete;
	virtual ~UIPrefab() {}
	virtual void onMouseClick() override final
	{
		Button::onMouseClick();
		nextScene = UIPrefabs::MenuScene;
		HandleScenes();
	}
};

template<>
class UIPrefab<UIPrefabs::MenuScene> :
	public Scene
{
	std::list<InteractableObject*> buttons;
public:
	UIPrefab() = default;
	void Update() override final
	{
		std::list<InteractableObject*>::iterator prev;
		for (auto i = buttons.begin(); i != buttons.end();)
		{
			prev = i++;
			(*prev)->Update();
			if (nextScene == UIPrefabs::_Reset)
			{
				_thing = false;
				nextScene = UIPrefabs::_Null;
			}
		}
	}
	void Init() override final
	{
		buttons.push_back(new UIPrefab<UIPrefabs::PlayButton, UIPrefabs::MenuScene>(buttons, C2D::Vector2(73, 18)));
		buttons.push_back(new UIPrefab<UIPrefabs::ExitButton, UIPrefabs::MenuScene>(buttons, C2D::Vector2(73, 22)));
		std::list<InteractableObject*>::iterator prev;
		for (auto i = buttons.begin(); i != buttons.end();)
		{
			prev = i++;
			(*prev)->Start();
		}
	}
};

template<>
class UIPrefab<UIPrefabs::GameScene> :
	public Scene
{
	std::list<InteractableObject*> buttons;
	GameManager demo;
public:
	UIPrefab() = default;
	void Update() override final
	{
		std::list<InteractableObject*>::iterator prev;
		for (auto i = buttons.begin(); i != buttons.end();)
		{
			prev = i++;
			(*prev)->Update();
			if (nextScene == UIPrefabs::_Reset)
			{
				_thing = false;
				nextScene = UIPrefabs::_Null;
			}
		}
		demo.Update();
	}
	void Init() override final
	{
		buttons.push_back(new UIPrefab<UIPrefabs::ExitButton, UIPrefabs::GameScene>(buttons, C2D::Vector2(142, 41)));
		std::list<InteractableObject*>::iterator prev;
		for (auto i = buttons.begin(); i != buttons.end();)
		{
			prev = i++;
			(*prev)->Start();
		}
		demo.Start();
	}
};

static void HandleScenes()
{
	switch (nextScene)
	{
	case UIPrefabs::_Exit:
	{
		SceneManager::setNextScene(nullptr);
		nextScene = UIPrefabs::_Reset;
		break;
	}
	case UIPrefabs::_Null:
	{
		/// ERROR???
		break;
	}
	case UIPrefabs::MenuScene:
	{
		SceneManager::setNextScene(new UIPrefab<UIPrefabs::MenuScene>());
		nextScene = UIPrefabs::_Reset;
		break;
	}
	case UIPrefabs::GameScene:
	{
		SceneManager::setNextScene(new UIPrefab<UIPrefabs::GameScene>());
		nextScene = UIPrefabs::_Reset;
		break;
	}
	default:
	{
		system("cls");

		//// DON'T TRY THIS AT HOME

		exit(0);
	}
	}
}
