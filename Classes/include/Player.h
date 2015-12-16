#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"

class Player : public cocos2d::Sprite{
public:
	static Player * create(void);
	void move(float x, float y);
	void update();
	void Boundaries();
	void idle();
	void LoseLives();

private:
	void initPlayer();
	float dirX, dirY;
	bool moving;
	float speed;
	float lives = 100;
};