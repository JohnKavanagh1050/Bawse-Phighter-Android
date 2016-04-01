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
			sprintf(str, "GameScreen/ninja_star.png", i);
			auto frame = SpriteFrame::create(str, Rect(0, 0, 30, 30)); //we assume that the sprites' dimentions are 30x30 rectangles.
			animFrames.pushBack(frame);
		}
		auto animation = Animation::createWithSpriteFrames(animFrames, 0.15f, INFINITE);
		auto animate = Animate::create(animation);

		playerBullet->runAction(animate);
		playerBullet->initBullet();

		return playerBullet;
	}
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