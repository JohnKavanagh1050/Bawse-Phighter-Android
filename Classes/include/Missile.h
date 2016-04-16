#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"

class Missile : public cocos2d::Sprite{
public:
	static Missile * createMissile(void);
	void initMissile();
	void update();
	bool getRemove();
	void setTrue();

private:
	int timeAlive;
	int timecounter;
	short const TIMETOLIVE = 60;
	bool remove;
};