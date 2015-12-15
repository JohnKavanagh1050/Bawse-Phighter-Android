#pragma once

#include "cocos2d.h"
#include "GameScene.h"
#include "UpgradeScene.h"

class MainMenu : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	void activateGameScene(Ref * pSender);
	void activateUpgradeScene(Ref * pSender);
	void exitGame(Ref* pSender);
	virtual bool init();

	CREATE_FUNC(MainMenu);
};