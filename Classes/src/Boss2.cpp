#include "Boss2.h"

USING_NS_CC;

Boss2 * Boss2::create(){
	Boss2 * boss2 = new Boss2();
	if (boss2 && boss2->initWithFile("GameScreen/boss2.png", Rect(0, 0, 139, 199)))
	{
		//Create and run animation
		Vector<SpriteFrame*> animFrames(4);
		char str[100] = { 0 };
		for (int i = 0; i < 4; i++)
		{
			sprintf(str, "GameScreen/boss2.png");
			auto frame = SpriteFrame::create(str, Rect(139 * i, 0, 139, 199));
			animFrames.pushBack(frame);
		}
		auto animation = CCAnimation::createWithSpriteFrames(animFrames, 0.15f, 100000);
		auto animate = CCAnimate::create(animation);
		cocos2d::Size size(139, 199);
		auto boss2Body = PhysicsBody::createBox(size * 0.75f);
		boss2Body->setCollisionBitmask(0x000005);
		boss2Body->setContactTestBitmask(true);
		boss2Body->setTag(50);
		boss2->setPhysicsBody(boss2Body);
		boss2->runAction(animate);
		boss2->initBoss2();
		boss2->setTag(50);
		return boss2;
	}

	CC_SAFE_DELETE(boss2);
	return NULL;
}

void Boss2::move(int directionParam){
	direction = directionParam;
}

std::vector<Missile*> Boss2::getBullets(){
	return currentBossMissiles;
}

std::vector<Missile*> Boss2::getBullets2(){
	return currentBossMissiles2;
}

std::vector<Missile*> Boss2::getBullets3(){
	return currentBossMissiles3;
}

std::vector<Missile*> Boss2::getBullets4(){
	return currentBossMissiles4;
}

void Boss2::deleteBossBullet(Level1* world, int i){
	world->removeChild(currentBossMissiles[i]);
	currentBossMissiles.erase(std::remove(currentBossMissiles.begin(), currentBossMissiles.end(), currentBossMissiles[i]));
}

void Boss2::deleteBossBullet2(Level1* world, int i){
	world->removeChild(currentBossMissiles2[i]);
	currentBossMissiles2.erase(std::remove(currentBossMissiles2.begin(), currentBossMissiles2.end(), currentBossMissiles2[i]));
}

void Boss2::deleteBossBullet3(Level1* world, int i){
	world->removeChild(currentBossMissiles3[i]);
	currentBossMissiles3.erase(std::remove(currentBossMissiles3.begin(), currentBossMissiles3.end(), currentBossMissiles3[i]));
}

void Boss2::deleteBossBullet4(Level1* world, int i){
	world->removeChild(currentBossMissiles4[i]);
	currentBossMissiles4.erase(std::remove(currentBossMissiles4.begin(), currentBossMissiles4.end(), currentBossMissiles4[i]));
}

void Boss2::update(Level1* world){
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	for (int i = 0; i < currentBossMissiles.size(); i++){
		if (currentBossMissiles[i]->getRemove()){
			deleteBossBullet(world, i);
		}
		else currentBossMissiles[i]->update1();
	}
	if (bossBulletCounter % (SECOND) == 0){
		Missile *missile = Missile::createMissile();
		currentBossMissiles.push_back(missile);
		missile->setPosition(getPosition().x, getPosition().y);
		world->addChild(missile, 3);
		bossBulletCounter = 0;
	}
	for (int i = 0; i < currentBossMissiles2.size(); i++){
		if (currentBossMissiles2[i]->getRemove()){
			deleteBossBullet2(world, i);
		}
		else currentBossMissiles2[i]->update2();
	}
	if (bossBulletCounter % (SECOND) == 0){
		Missile *missile = Missile::createMissile();
		currentBossMissiles2.push_back(missile);
		missile->setPosition(getPosition().x, getPosition().y);
		world->addChild(missile, 3);
		bossBulletCounter = 0;
	}
	for (int i = 0; i < currentBossMissiles3.size(); i++){
		if (currentBossMissiles3[i]->getRemove()){
			deleteBossBullet3(world, i);
		}
		else currentBossMissiles3[i]->update3();
	}
	if (bossBulletCounter % (SECOND) == 0){
		Missile *missile = Missile::createMissile();
		currentBossMissiles3.push_back(missile);
		missile->setPosition(getPosition().x, getPosition().y);
		world->addChild(missile, 3);
		bossBulletCounter = 0;
	}
	for (int i = 0; i < currentBossMissiles4.size(); i++){
		if (currentBossMissiles4[i]->getRemove()){
			deleteBossBullet4(world, i);
		}
		else currentBossMissiles4[i]->update4();
	}
	if (bossBulletCounter % (SECOND) == 0){
		Missile *missile = Missile::createMissile();
		currentBossMissiles4.push_back(missile);
		missile->setPosition(getPosition().x, getPosition().y);
		world->addChild(missile, 3);
		bossBulletCounter = 0;
	}
	setPosition(Vec2(s.width / 2, s.height / 2));
		
	//make boss look l
	if (bossCounter >= 30){
		setRotation(5.0f);
	}
	if (bossCounter >= 60){
		// rotate sprite by -20 degrees
		setRotation(-10.0f);
		bossCounter = 0;
	}

	bossCounter++;
	bossBulletCounter++;
}

float Boss2::getLives(){
	return lives;
}

void Boss2::loseLives(){
	lives--;
}

void Boss2::initBoss2(){
	lives = 100;
	bossCounter = 0;
	bossBulletCounter = 0;
}