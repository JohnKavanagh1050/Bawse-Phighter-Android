#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"
#include "BossBullet.h"
#include "GameScene.h"

class Boss2 : public cocos2d::Sprite{
public:
	static Boss2 * create(void);
	void initBoss2();
	void move(int directionParam);
	void update(Level1* world);
	void idle();
	void Defeated();
	void deleteBossBullet(Level1* world, int i);
	void loseLives();

	bool Hit();

	float getLives();

	std::vector<BossBullet*> getBullets();
private:
	const short SECOND = 60;
	int direction, lives;
	bool moving;
	bool hit;
	short bossCounter;

	std::vector<BossBullet*> currentBossBullets;
};
