#include "Bullet.h"

Bullet * Bullet::createPlayerBullet()
{
	Bullet * playerBullet = new Bullet();
	if (playerBullet && playerBullet->initWithFile("GameScreen/bullet.png"))
	{
		playerBullet->autorelease();
		playerBullet->initBullet();
		return playerBullet;
	}

	CC_SAFE_DELETE(playerBullet);
	return NULL;
}

Bullet * Bullet::createBossBullet()
{
	Bullet * bossBullet = new Bullet();
	if (bossBullet && bossBullet->initWithFile("GameScreen/enemy bullet.png"))
	{
		bossBullet->autorelease();
		bossBullet->initBullet();
		return bossBullet;
	}

	CC_SAFE_DELETE(bossBullet);
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
	setPositionY(getPositionY() - 3);
}