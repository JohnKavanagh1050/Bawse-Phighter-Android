#pragma once

#include "cocos2d.h"
#include "PauseScene.h"
#include "GameData.h"
#include "GameOverScene.h"
#include "GameComplete.h"
#include "GameStates.h"
#include "GameScene2.h"
#include "Bullet.h"
#include "BossBullet.h"
#include "HealthBar.h"

#include "SimpleAudioEngine.h"  

#include <iostream>
class Boss;
class Boss2;
class Player;
class Level1 : public cocos2d::Layer
{
private:
	GameStates m_gameState;
	Player* player;
	Boss* boss;
	Boss2* boss2;
	//HealthBar* healthBar;

	//std::vector<Bullet*> currentPlayerBullets;
	//std::vector<BossBullet*> currentBossBullets;

	// local variable declaration:
	char level = 'A';

public:
	cocos2d::PhysicsWorld * sceneWorld;
	void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };
	static cocos2d::Scene* createScene();
	virtual bool init();
	// Called when user pauses gameplay.
	void activatePauseScene(Ref *pSender);
	// Called at game over
	void activateGameOverScene(Ref *pSender);
	// called for game won scene
	void activateGameCompleteScene(Ref *pSender);
	//call menu
	void activateMainMenuScene(Ref *pSender);
	void activateGameScene2(Ref * pSender);
	void addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin);
	void update(float dt);

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
	//void checkBoundaries();
	bool onContactBegin(cocos2d::PhysicsContact &contact);

	CREATE_FUNC(Level1);
};
#include "Boss.h"
#include "Boss2.h"
#include "Player.h"