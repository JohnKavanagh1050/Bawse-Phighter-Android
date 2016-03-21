#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"

class BossBullet : public cocos2d::Sprite{
public:
	static BossBullet * createBossBullet(void);
	void initBullet();
	void update();
	bool getRemove();
	
private:
	int timeAlive;
	int timecounter;
	short const TIMETOLIVE = 60;
	bool remove;
};