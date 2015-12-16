#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"

class Bullet : public cocos2d::Sprite{
public:
	static Bullet * createPlayerBullet(void);
	static Bullet * createBossBullet(void);
	void initBullet();
	void updatePlayerBullet();
	void updateBossBullet();
private:

};