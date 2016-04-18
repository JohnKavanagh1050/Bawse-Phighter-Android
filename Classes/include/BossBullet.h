#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"

class BossBullet : public cocos2d::Sprite{
public:
	static BossBullet * createBossBullet(void);
	static BossBullet * createBossBullet2(void);
	void initBullet();
	void update();
	void update2();
	bool getRemove();
	void setTrue();
	
private:
	int timeAlive;
	int timecounter;
	short const TIMETOLIVE = 60;
	bool remove;
	char state = 'A';
};