#include "SceneManager.h"

SceneManager& SceneManager::getInstance()
{
	_instanceCount++;
	if (_instance == nullptr)
	{
		_instance = new SceneManager;
	}
	return *_instance;
}
void SceneManager::releaseInstance()
{
	_instanceCount--;
	if (_instanceCount == 0 && _instance != nullptr)
	{
		delete _instance;
		_instance = nullptr;
	}
	return;
}
SceneManager::SceneManager()
{
	Init();
}
SceneManager::~SceneManager()
{
	localHandler.releaseInstance();
	localMHandler.releaseInstance();
}

void SceneManager::Init()
{
 /// ??? alot of stuff has to be added
}

SceneManager* SceneManager::_instance = nullptr;
int SceneManager::_instanceCount = 0;
Scene* SceneManager::currentScene = nullptr;
Scene* SceneManager::nextScene = nullptr;