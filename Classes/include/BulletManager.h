#pragma once

#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include "GameData.h"
#include "Bullet.h"
#include "cocos2d.h"

class GameScreen;

class BulletManager{
public:
	static BulletManager* GetInstance();

	//void setPlayer(Player* player);
	//void setBoss(Boss* player);
	//bool checkCollision();

	//Return a pointer to a new bullet if ne wa created. Otherwise null.
	void update(GameScreen* world, Bullet* &playerBullet, Bullet* &bossBullet);
	void deleteBossBullet(GameScreen* world,  Bullet* &bossBullet);
	void deletePlayerBullet(GameScreen* world, Bullet* &playerBullet);

private:
	std::list<Bullet*> currentPlayerBullets;
	std::list<Bullet*> currentBossBullets;
	const short SECOND = 60;
	short bossCounter;
	short playerCounter;
	bool pBullet = false;
	bool bBullet = false;
	static BulletManager* instance;
	static bool instanceFlag;
};
#include "GameScene.h"
#endif