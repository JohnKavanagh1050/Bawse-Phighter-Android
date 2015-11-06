#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"

class Bullet : public cocos2d::Sprite{
public:
	static Bullet * create(void);
	void initBullet();
	void update();

private:


};