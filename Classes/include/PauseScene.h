#pragma once

#include "cocos2d.h"
#include "GameScene.h"
#include "MainMenuScene.h"

class PauseMenu : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	// Called when resume is selected.
	void resume(Ref *pSender);
	// Called when main menu is selected.
	void activateMainMenuScene(Ref *pSender);
	// Called when retry is selected.
	void retry(Ref *pSender);

	CREATE_FUNC(PauseMenu);
};