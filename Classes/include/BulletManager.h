#pragma once

#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include "GameData.h"
#include "Bullet.h"


class GameScreen;

class BulletManager{
public:
	static BulletManager* GetInstance();

	//Return a pointer to a new bullet if ne wa created. Otherwise null.
	void update(GameScreen* world, Bullet* &playerBullet, Bullet* &bossBullet);

private:
	std::list<Bullet*> currentPlayerBullets;
	std::list<Bullet*> currentBossBullets;
	const short SECOND = 60;
	short bossCounter;
	short playerCounter;
	
	//BulletManager::BulletManager() {}
	static BulletManager* instance;
	static bool instanceFlag;
};
#include "GameScene.h"
#endif