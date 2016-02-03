#pragma once

#include "cocos2d.h"
#include "PauseScene.h"
#include "GameData.h"
#include "GameOverScene.h"
#include "Player.h"
#include "GameStates.h"

#include "SimpleAudioEngine.h"  

class Boss;

class GameScreen : public cocos2d::Layer
{
private:
	GameStates m_gameState;
	Player* player;
	Boss* boss;

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	// Called when user pauses gameplay.
	void activatePauseScene(Ref *pSender);
	// Called at game over 
	void activateGameOverScene(Ref *pSender);
	void addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin);
	void update(float dt);

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

	CREATE_FUNC(GameScreen);
};
#include "Boss.h"