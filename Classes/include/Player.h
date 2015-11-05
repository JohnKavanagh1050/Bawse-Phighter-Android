#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"

class Player : public cocos2d::Sprite{
public:
	static Player * create(void);
	void moveRL(int directionParam);
	void moveUD(int directionParam);
	void update();
private:
	void initPlayer();
	int direction;
	bool movingRL;
	bool movingUD;

};