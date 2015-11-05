#pragma once

#include "LevelLoader.h"
#include "cocos2d.h"

class  AppDelegate : private cocos2d::Application
{
private: 
	std::shared_ptr<GameData> m_ptr;

public:
	AppDelegate();
	virtual ~AppDelegate();

	virtual bool applicationDidFinishLaunching();
	virtual void applicationDidEnterBackground();
	virtual void applicationWillEnterForeground();
};