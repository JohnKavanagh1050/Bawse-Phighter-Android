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
		auto animation = CCAnimation::createWithSpriteFrames(animFrames, 0.15f, 100000);
		auto animate = CCAnimate::create(animation);
		//make body for collisions
		cocos2d::Size size(36, 36);
		auto bossBulletBody = PhysicsBody::createBox(size);
		bossBulletBody->setCollisionBitmask(0x000004);
		bossBulletBody->setContactTestBitmask(true);
		bossBullet->setPhysicsBody(bossBulletBody);
		bossBulletBody->setTag(40);
		bossBullet->runAction(animate);
		bossBullet->initBullet();
		bossBullet->setTag(40);
		return bossBullet;
	}

	CC_SAFE_DELETE(bossBullet);
	return NULL;
}


BossBullet * BossBullet::createBossBullet2()
{
	BossBullet * bossBullet2 = new BossBullet();
	if (bossBullet2 && bossBullet2->initWithFile("GameScreen/ss_boss1_attack2.png", Rect(0, 0, 36, 36)))
	{
		//Create and run animation
		Vector<SpriteFrame*> animFrames(5);
		char str[100] = { 0 };
		for (int i = 0; i < 5; i++)
		{
			sprintf(str, "GameScreen/ss_boss1_attack2.png");
			auto frame = SpriteFrame::create(str, Rect(36 * i, 0, 36, 36)); //we assume that the sprites' dimentions are 30x30 rectangles.
			animFrames.pushBack(frame);
		}
		auto animation = CCAnimation::createWithSpriteFrames(animFrames, 0.15f, 100000);
		auto animate = CCAnimate::create(animation);
		//make body for collisions
		cocos2d::Size size(36, 36);
		auto bossBulletBody = PhysicsBody::createBox(size);
		bossBulletBody->setCollisionBitmask(0x000007);
		bossBulletBody->setContactTestBitmask(true);
		bossBullet2->setPhysicsBody(bossBulletBody);
		bossBulletBody->setTag(70);
		bossBullet2->runAction(animate);
		bossBullet2->initBullet();
		bossBullet2->setTag(70);
		return bossBullet2;
	}

	CC_SAFE_DELETE(bossBullet2);
	return NULL;
}

BossBullet * BossBullet::createBossBullet3()
{
	BossBullet * bossBullet3 = new BossBullet();
	if (bossBullet3 && bossBullet3->initWithFile("GameScreen/ss_boss1_attack3.png", Rect(0, 0, 36, 36)))
	{
		//Create and run animation
		Vector<SpriteFrame*> animFrames(5);
		char str[100] = { 0 };
		for (int i = 0; i < 5; i++)
		{
			sprintf(str, "GameScreen/ss_boss1_attack3.png");
			auto frame = SpriteFrame::create(str, Rect(36 * i, 0, 36, 36)); //we assume that the sprites' dimentions are 30x30 rectangles.
			animFrames.pushBack(frame);
		}
		auto animation = CCAnimation::createWithSpriteFrames(animFrames, 0.15f, 100000);
		auto animate = CCAnimate::create(animation);
		//make body for collisions
		cocos2d::Size size(36, 36);
		auto bossBulletBody = PhysicsBody::createBox(size);
		bossBulletBody->setCollisionBitmask(0x000006);
		bossBulletBody->setContactTestBitmask(true);
		bossBullet3->setPhysicsBody(bossBulletBody);
		bossBulletBody->setTag(60);
		bossBullet3->runAction(animate);
		bossBullet3->initBullet();
		bossBullet3->setTag(60);
		return bossBullet3;
	}

	CC_SAFE_DELETE(bossBullet3);
	return NULL;
}

bool BossBullet::getRemove(){
	return remove;
}

void BossBullet::initBullet(){
	timecounter1 = timecounter2 = timecounter3 = timeAlive = 0;
	remove = false;
}

void BossBullet::setTrue(){
	remove = true;
}

void BossBullet::update(){
	setPositionY(getPositionY()-3);
	timecounter1++;
	if (timecounter1 >= 300){
		remove = true;
	}
}

void BossBullet::update2(){
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	switch (state)
	{
	case 'A':
		if (getPositionX() >= s.width / 2){
			setPosition(getPositionX() + 2, getPositionY() + 1);
		}
		else{
			setPosition(getPositionX() - 2, getPositionY() + 1);
		}
		if (getPositionY() >= s.height - 50)
		{
			state = 'B';
		}
		break;
	case 'B':
		setPosition(getPositionX(), getPositionY() - 10);
		break;
	}

	timecounter2++;
	if (timecounter2 >= 300){
		remove = true;
	}
}

void BossBullet::update3(){
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	switch (state2)
	{
	case 'A':
		if (getPositionX() >= s.width + 200 / 2){
			setPosition(getPositionX() - 4, getPositionY() - 8);
		}
		else if (getPositionX() <= s.width - 200 / 2){
			setPosition(getPositionX() + 4, getPositionY() - 8);
		}
		if (getPositionY() <= 100)
		{
			state2 = 'B';
		}
		break;
	case 'B':
			setPosition(getPositionX(), 100);
		break;
	}

	timecounter3++;
	if (timecounter3 >= 250){
		remove = true;
	}
}