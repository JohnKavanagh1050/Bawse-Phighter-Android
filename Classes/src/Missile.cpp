#include "Missile.h"

USING_NS_CC;

Missile * Missile::createMissile(){
	Missile * missile = new Missile();
	if (missile && missile->initWithFile("GameScreen/ss_boss1_attack.png", Rect(0, 0, 36, 36)))
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
		bossBulletBody->setCollisionBitmask(0x000008);
		bossBulletBody->setContactTestBitmask(true);
		missile->setPhysicsBody(bossBulletBody);
		missile->setTag(80);
		missile->runAction(animate);
		missile->initMissile();
		missile->setTag(80);
		return missile;
	}

	CC_SAFE_DELETE(missile);
	return NULL;
}


Missile * Missile::createMissile2(){
	Missile * missile = new Missile();
	if (missile && missile->initWithFile("GameScreen/ss_boss_attack.png", Rect(0, 0, 36, 36)))
	{
		//Create and run animation
		Vector<SpriteFrame*> animFrames(5);
		char str[100] = { 0 };
		for (int i = 0; i < 5; i++)
		{
			sprintf(str, "GameScreen/ss_boss_attack.png");
			auto frame = SpriteFrame::create(str, Rect(36 * i, 0, 36, 36)); //we assume that the sprites' dimentions are 30x30 rectangles.
			animFrames.pushBack(frame);
		}
		auto animation = CCAnimation::createWithSpriteFrames(animFrames, 0.15f, 100000);
		auto animate = CCAnimate::create(animation);
		//make body for collisions
		cocos2d::Size size(36, 36);
		auto bossBulletBody = PhysicsBody::createBox(size);
		bossBulletBody->setCollisionBitmask(0x000008);
		bossBulletBody->setContactTestBitmask(true);
		missile->setPhysicsBody(bossBulletBody);
		missile->setTag(80);
		missile->runAction(animate);
		missile->initMissile();
		missile->setTag(80);
		return missile;
	}

	CC_SAFE_DELETE(missile);
	return NULL;
}

bool Missile::getRemove(){
	return remove;
}

void Missile::initMissile(){
	timecounter = timeAlive = 0;
	remove = false;
}

void Missile::setTrue(){
	remove = true;
}

void Missile::update1(){
	setPosition(getPositionX() + 6, getPositionY() + 4);
	//setPosition(getPositionX() + num, getPositionY() + num);
	timecounter++;
	if (timecounter >= 1000){
		remove = true;
	}
}
void Missile::update2(){
	setPosition(getPositionX() - 6, getPositionY() + 4);
	//setPosition(getPositionX() + num, getPositionY() + num);
	timecounter++;
	if (timecounter >= 1000){
		remove = true;
	}
}
void Missile::update3(){
	setPosition(getPositionX() + 6, getPositionY() - 4);
	//setPosition(getPositionX() + num, getPositionY() + num);
	timecounter++;
	if (timecounter >= 1000){
		remove = true;
	}
}
void Missile::update4(){
	setPosition(getPositionX() - 6, getPositionY() - 4);
	//setPosition(getPositionX() + num, getPositionY() + num);
	timecounter++;
	if (timecounter >= 1000){
		remove = true;
	}
}
