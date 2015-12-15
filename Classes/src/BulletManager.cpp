#include "BulletManager.h"


bool BulletManager::instanceFlag = false;
BulletManager* BulletManager::instance = NULL;

BulletManager* BulletManager::GetInstance() {
	if (!instanceFlag){
		instance = new BulletManager;
		instanceFlag = true;
		return instance;
	}
	else{
		return instance;
	}
}

Bullet* BulletManager::update(GameScreen* world)
{
	Bullet* newBullet = nullptr;

	if (counter % (SECOND / 4) == 0){
		newBullet = Bullet::create();
		currentBullets.push_back(newBullet);
		world->addChild(newBullet, 5);
		counter = 0;
	}
	//like a for each statement
	for (Bullet* e : currentBullets) {
		//had to change from for each e was out of scope before it would compile apk
		e->updatePlayerBullet();
	}
	counter++;

	return newBullet;
}
