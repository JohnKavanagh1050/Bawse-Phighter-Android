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

void BulletManager::update()
{
	if (counter % (SECOND * 3) == 0){
		currentBullets.push_back(new Bullet());
		counter = 0;
	}
	for each (Bullet* e in currentBullets) {
		e->update();
	}
	counter++;
}
