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
	Bullet* update(GameScreen* world);

private:
	std::list<Bullet*> currentBullets;
	const short SECOND = 60;
	short counter;

	BulletManager::BulletManager() {}
	static BulletManager* instance;
	static bool instanceFlag;
};
#include "GameScene.h"
#endif