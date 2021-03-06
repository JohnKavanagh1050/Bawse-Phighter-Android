#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"

class Missile : public cocos2d::Sprite{
public:
	static Missile * createMissile(void);
	static Missile * createMissile2(void);
	static Missile * createMissile3(void);
	void initMissile();
	//update blue bullets
	void update1();
	void update2();
	void update3();
	void update4();
	//update yellow bullets
	void update5();
	void update6();
	void update7();
	void update8();
	//update red bullets
	void update9();
	void update10();
	void update11();
	void update12();
	bool getRemove();
	void setTrue();
	void rotateNodeToPoint(cocos2d::Node* node, cocos2d::Point point);

private:
	int timeAlive;
	int timecounter;
	short const TIMETOLIVE = 60;
	bool remove;
	char state = 'A';
};