#pragma once


#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"

class Bullet : public cocos2d::Sprite{
public:
	static Bullet * createPlayerBullet(void);
	void initBullet();
	void updatePlayerBullet();
	bool getRemove();
	void animateBullet();
private:
	int timeAlive;
	int timecounter;
	short const TIMETOLIVE = 60;
	bool remove;

	//std::vector<SpriteFrame*> animFrames(4);
};