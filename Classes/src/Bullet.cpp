#include "Bullet.h"

Bullet * Bullet::create()
{
	Bullet * bullet = new Bullet();
	if (bullet && bullet->initWithFile("GameScreen/bullet.png"))
	{
		bullet->autorelease();
		bullet->initBullet();
		return bullet;
	}

	CC_SAFE_DELETE(bullet);
	return NULL;
}

void Bullet::initBullet(){

}

void Bullet::updatePlayerBullet()
{
	setPositionY(getPositionY() + 5);
}

void Bullet::updateBossBullet()
{
	setPositionY(getPositionY() - 5);
}