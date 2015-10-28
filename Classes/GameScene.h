#pragma once

#include "cocos2d.h"
#include "PauseScene.h"
#include "GameOverScene.h"

class GameScreen : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	// Called when user pauses gameplay.
	void activatePauseScene(Ref *pSender);
	// Called at game over 
	void activateGameOverScene(Ref *pSender);

	CREATE_FUNC(GameScreen);
};