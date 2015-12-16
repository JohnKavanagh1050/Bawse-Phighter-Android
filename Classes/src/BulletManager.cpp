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

void BulletManager::update(GameScreen* world, Bullet* &playerBullet, Bullet* &bossBullet)
{

	if (bossCounter % (SECOND) == 0){
		bossBullet = Bullet::createBossBullet();
		currentBossBullets.push_back(bossBullet);
		world->addChild(bossBullet, 5);
		bossCounter = 0;
	}

	if (playerCounter % (SECOND / 4) == 0){
		playerBullet = Bullet::createPlayerBullet();
		currentPlayerBullets.push_back(playerBullet);
		world->addChild(playerBullet, 5);
		playerCounter = 0;
	}
	//like a for each statement
	for (Bullet* e : currentPlayerBullets) {
		//had to change from for each e was out of scope before it would compile apk
		e->updatePlayerBullet();
	}

	for (Bullet* f : currentBossBullets) {
		f->updateBossBullet();
	}
	playerCounter++;
	bossCounter++;

	return;
}
