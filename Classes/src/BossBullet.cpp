#include "BossBullet.h"

USING_NS_CC;

BossBullet * BossBullet::createBossBullet()
{
	BossBullet * bossBullet = new BossBullet();
	if (bossBullet && bossBullet->initWithFile("GameScreen/ss_boss1_attack.png", Rect(0, 0, 36, 36)))
	{
		//Create and run animation
		Vector<SpriteFrame*> animFrames(5);
		char str[100] = { 0 };
		for (int i = 0; i < 5; i++)
		{
			sprintf(str, "GameScreen/ss_boss1_attack.png");
			auto frame = SpriteFrame::create(str, Rect(36 * i, 0, 36, 36)); //we assume that the sprites' dimentions are 30x30 rectangles.
			animFrames.pushBack(frame);
		}
		auto animation = Animation::createWithSpriteFrames(animFrames, 0.15f, 100000);
		auto animate = Animate::create(animation);
		//make body for collisions
		cocos2d::Size size(36, 36);
		auto bossBulletBody = PhysicsBody::createBox(size);
		bossBulletBody->setCollisionBitmask(0x000004);
		bossBulletBody->setContactTestBitmask(true);
		bossBullet->setPhysicsBody(bossBulletBody);
		bossBullet->runAction(animate);
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
	timecounter = timeAlive = 0;
	remove = false;
}

void BossBullet::update()
{
	setPositionY(getPositionY()-3);
	timecounter++;
	if (timecounter >= 1000){
		remove = true;
	}
}