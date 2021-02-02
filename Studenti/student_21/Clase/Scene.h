#pragma once
#include "InputProcesser.h"
#include "NextLevelConsoleHandler.h"
class Scene
{
	ConsoleHandlerV2& localHandler = ConsoleHandlerV2::getInstance();
	MouseHandler& localMHandler = MouseHandler::getInstance();
protected:
	bool _thing = true; //i'm low on time sry
public:
	Scene() {}
	Scene(const Scene&) = delete;
	Scene& operator= (const Scene&) = delete;
	virtual ~Scene() {}
	void Run()
	{
		while (_thing)
		{
			Sleep(17);
			localHandler.reset();
			localMHandler.processInput();
			Update();
			localHandler.Draw();
		}
	}
	void Stop()
	{
		localHandler.releaseInstance();
		localMHandler.releaseInstance();
	}
	virtual void Init() = 0;
private:
	virtual void Update() = 0;
};

