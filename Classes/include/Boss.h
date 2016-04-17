#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"
#include "BossBullet.h"
#include "Missile.h"
#include "GameScene.h"
#include "Player.h"

class Boss : public cocos2d::Sprite{
public:
	static Boss * create(void);
	void initBoss();
	void move(int directionParam);
	void update(Level1* world);
	void idle();
	void Defeated();
	void deleteBossBullet(Level1* world, int i);
	void deleteMissile(Level1* world, int i);
	void loseLives();

	bool Hit();

	float getLives();

	std::vector<BossBullet*> getBullets();
	std::vector<Missile*> getMissiles();
private:
	const short SECOND = 60;
	int direction, lives;
	bool moving;
	bool hit;
	short bossCounter;
	short missileCounter;
//	Player* player;

	std::vector<BossBullet*> currentBossBullets;
	std::vector<Missile*> currentMissiles;

	//CCProgressTimer *healthBar;
};
