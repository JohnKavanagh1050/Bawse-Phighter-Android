#include "Bullet.h"

USING_NS_CC;

Bullet * Bullet::createPlayerBullet()
{
	Bullet * playerBullet = new Bullet();

	if (playerBullet && playerBullet->initWithFile("GameScreen/ninja_star.png"))
	{

		//Create and run animation
		Vector<SpriteFrame*> animFrames(3);
		char str[100] = { 0 };
		for (int i = 0; i < 3; i++)
		{
			sprintf(str, "GameScreen/ninja_star.png");
			auto frame = SpriteFrame::create(str, Rect(27 * i, 0, 27, 27)); //we assume that the sprites' dimentions are 30x30 rectangles.
			animFrames.pushBack(frame);
		}
		auto animation = Animation::createWithSpriteFrames(animFrames, 0.05f, 100000);
		auto animate = Animate::create(animation);
		//make body for collisions
		cocos2d::Size size(27, 27);
		auto bulletBody = PhysicsBody::createBox(size);
		bulletBody->setCollisionBitmask(0x000003);
		bulletBody->setContactTestBitmask(true);
		playerBullet->setPhysicsBody(bulletBody);
		playerBullet->runAction(animate);
		playerBullet->initBullet();

		return playerBullet;
	}
	CC_SAFE_DELETE(playerBullet);
	return NULL;
}

void Bullet::animateBullet()
{
	
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