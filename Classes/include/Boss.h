#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"
#include "BossBullet.h"
#include "GameScene.h"
#include "Player.h"

class Boss : public cocos2d::Sprite{
public:
	static Boss * create(void);
	void initBoss();
	void move(int directionParam);
	std::vector<BossBullet*> getBullets();
	void update(GameScreen* world);
	void idle();
	void Hit();
	void Defeated();
	void deleteBossBullet(GameScreen* world, int i);

private:
	const short SECOND = 60;
	int direction, lives;
	bool moving;
	bool hit;
	short bossCounter;
//	Player* player;

	std::vector<BossBullet*> currentBossBullets;
};
