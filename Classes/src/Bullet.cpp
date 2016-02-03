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

void Bullet::initBullet(){

}

void Bullet::updatePlayerBullet(){
	setPositionY(getPositionY() + 5);
}