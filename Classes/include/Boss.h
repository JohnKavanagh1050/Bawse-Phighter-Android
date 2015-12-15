#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"

class Boss : public cocos2d::Sprite{
public:
	static Boss * create(void);
	void move(int directionParam);
	void update();
	void idle();

private:
	void initBoss();
	int direction;
	bool moving;

};