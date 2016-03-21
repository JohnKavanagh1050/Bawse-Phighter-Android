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

bool Bullet::getRemove(){
	return remove;
}

void Bullet::initBullet(){
	timecounter = timeAlive = 0;
	remove = false;
}

void Bullet::updatePlayerBullet(){
	setPositionY(getPositionY() + 5);

	timecounter++;
	if (timecounter >= 1000){
		remove = true;
	}
}