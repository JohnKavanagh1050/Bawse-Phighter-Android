#pragma once

#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include "GameData.h"
#include "Bullet.h"

class BulletManager{
public:
	static BulletManager* GetInstance();
	void update();

private:
	std::list<Bullet*> currentBullets;
	const short SECOND = 60;
	short counter;

	BulletManager::BulletManager() {}
	static BulletManager* instance;
	static bool instanceFlag;
};

#endif