#include "BossBullet.h"

BossBullet * BossBullet::createBossBullet()
{
	BossBullet * bossBullet = new BossBullet();
	if (bossBullet && bossBullet->initWithFile("GameScreen/enemy bullet.png"))
	{
		bossBullet->autorelease();
		bossBullet->initBullet();
		return bossBullet;
	}

	CC_SAFE_DELETE(bossBullet);
	return NULL;
}

bool BossBullet::getRemove(){
	return remove;
}

void BossBullet::initBullet(){

}

void BossBullet::update()
{
	setPositionY(getPositionY() - 3);
	timecounter++;
	if (timecounter >= 600){
		remove = true;
	}
}