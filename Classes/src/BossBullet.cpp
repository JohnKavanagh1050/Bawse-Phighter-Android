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

void BossBullet::initBullet(){

}

void BossBullet::updateBossBullet()
{
	setPositionY(getPositionY() - 3);
}