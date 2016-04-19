#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"

class BossBullet : public cocos2d::Sprite{
public:
	static BossBullet * createBossBullet(void);
	static BossBullet * createBossBullet2(void);
	static BossBullet * createBossBullet3(void);
	void initBullet();
	void update();
	void update2();
	void update3();
	bool getRemove();
	void setTrue();
	
private:
	int timeAlive;
	int timecounter1, timecounter2, timecounter3;
	short const TIMETOLIVE = 60;
	bool remove;
	char state = 'A';
	char state2 = 'A';
};