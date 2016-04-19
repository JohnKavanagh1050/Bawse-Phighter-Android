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
		boss2->autorelease();
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
	return currentBossBullets;
}

std::vector<Missile*> Boss2::getBullets2(){
	return currentBossBullets2;
}

std::vector<Missile*> Boss2::getBullets3(){
	return currentBossBullets3;
}

void Boss2::deleteBossBullet(Level1* world, int i){
	world->removeChild(currentBossBullets[i]);
	currentBossBullets.erase(std::remove(currentBossBullets.begin(), currentBossBullets.end(), currentBossBullets[i]));
}

void Boss2::deleteBossBullet2(Level1* world, int i){
	world->removeChild(currentBossBullets2[i]);
	currentBossBullets2.erase(std::remove(currentBossBullets2.begin(), currentBossBullets2.end(), currentBossBullets2[i]));
}

void Boss2::deleteBossBullet3(Level1* world, int i){
	world->removeChild(currentBossBullets3[i]);
	currentBossBullets3.erase(std::remove(currentBossBullets3.begin(), currentBossBullets3.end(), currentBossBullets3[i]));
}

void Boss2::update(Level1* world){
	/*for (int i = 0; i < currentBossBullets.size(); i++){
		if (currentBossBullets[i]->getRemove()){
			deleteBossBullet(world, i);
		}
		else currentBossBullets[i]->update();
	}
	if (bossBulletCounter % (SECOND / 2) == 0){
		Missile *missile = Missile::createMissile();
		currentBossBullets.push_back(missile);
		missile->setPosition(getPosition().x, getPosition().y);
		world->addChild(missile, 3);
		bossBulletCounter = 0;
	}*/

	CCSize s = CCDirector::sharedDirector()->getWinSize();
	setPosition(Vec2(s.width / 2, s.height / 2));

	//make boss look l
	if (bossCounter >= 30){
		setRotation(5.0f);
		// increases just X scale by 2.0
	}
	if (bossCounter >= 60){
		// rotate sprite by -20 degrees
		setRotation(-10.0f);
		bossCounter = 0;
		// increases just X scale by 2.0
	}

	bossCounter++;
	bossBulletCounter++;
	return;
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