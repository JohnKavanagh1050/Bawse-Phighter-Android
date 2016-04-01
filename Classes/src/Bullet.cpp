#include "Bullet.h"

Bullet * Bullet::createPlayerBullet()
{
	Bullet * playerBullet = new Bullet();

	if (playerBullet && playerBullet->initWithFile("GameScreen/bullet.png"))
	{
		playerBullet->initBullet();
		return playerBullet;
	}
}

void Bullet::animateBullet()
{
	/*std::vector<SpriteFrame*> animFrames;
	animFrames.reserve(12);
	animFrames.pushBack(SpriteFrame::create(GameScreen / bullet.png, Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_Front2.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_Front3.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_Left1.png", Rect(0, 0, 65, 81)));


	// create the animation out of the frames
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);

	// run it and repeat it forever
	mySprite->runAction(RepeatForever::create(animate));*/
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