#include "GameScene.h"
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

void Bullet::update()
{
	this->setPositionY(this->getPositionY() + 5);
}