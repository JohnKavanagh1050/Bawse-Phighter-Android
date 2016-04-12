#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "GameStates.h"
#include "GameScene.h"
#include "Bullet.h"

class Player : public cocos2d::Sprite{
public:
	static Player * create(void);

	void move(float x, float y);
	void update(Level1* world);
	void Boundaries();
	void idle();
	void loseLives();
	void deletePlayerBullet(Level1* world, int i);

	bool Hit();

	float getLives();

	std::vector<Bullet*> getBullets();
private:
	void initPlayer();

	float dirX, dirY;
	float speed;
	float lives = 10;

	bool moving;
	bool hit;

	short counter;
	const short SECOND = 60;

	std::vector<Bullet*> currentPlayerBullets;
};