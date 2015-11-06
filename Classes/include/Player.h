#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"

class Player : public cocos2d::Sprite{
public:
	static Player * create(void);
	void move(int directionParam);
	void update();
	void Boundaries();
	void idle();

private:
	void initPlayer();
	int direction;
	bool moving;


};