#include "Boss.h"

USING_NS_CC;

Boss * Boss::create(){
	Boss * boss = new Boss();
	if (boss && boss->initWithFile("GameScreen/ss_boss1.png", Rect(134, 137, 134, 137)))
	{
		//Create and run animation
		Vector<SpriteFrame*> animFrames(7);
		char str[100] = { 0 };
		for (int i = 0; i < 7; i++)
		{
			sprintf(str, "GameScreen/ss_boss1.png");
			auto frame = SpriteFrame::create(str, Rect(134 * i, 137, 134, 137)); 
			//auto frame = SpriteFrame::create(str, Rect(201 * i, 206, 201, 206)); //we assume that the sprites' dimentions are 30x30 rectangles.
			animFrames.pushBack(frame);
		}
		auto animation = CCAnimation::createWithSpriteFrames(animFrames, 0.15f, 100000);
		auto animate = CCAnimate::create(animation);
		cocos2d::Size size(134, 137);
		auto bossBody = PhysicsBody::createBox(size);
		bossBody->setCollisionBitmask(0x000003);
		bossBody->setContactTestBitmask(true);
		bossBody->setTag(30);
		boss->setPhysicsBody(bossBody);
		boss->runAction(animate);
		boss->initBoss();
		boss->setTag(30);
		return boss;
	}

	CC_SAFE_DELETE(boss);
	return NULL;
}

void Boss::move(int directionParam){
	direction = directionParam;
	moving = true;
}

std::vector<BossBullet*> Boss::getBullets(){
	return currentBossBullets;
}

std::vector<BossBullet*> Boss::getBullets2(){
	return currentBossBullets2;
}

std::vector<BossBullet*> Boss::getBullets3(){
	return currentBossBullets3;
}

void Boss::deleteBossBullet(Level1* world, int i){
	world->removeChild(currentBossBullets[i]);
	currentBossBullets.erase(std::remove(currentBossBullets.begin(), currentBossBullets.end(), currentBossBullets[i]));
}

void Boss::deleteBossBullet2(Level1* world, int i){
	world->removeChild(currentBossBullets2[i]);
	currentBossBullets2.erase(std::remove(currentBossBullets2.begin(), currentBossBullets2.end(), currentBossBullets2[i]));
}

void Boss::deleteBossBullet3(Level1* world, int i){
	world->removeChild(currentBossBullets3[i]);
	currentBossBullets3.erase(std::remove(currentBossBullets3.begin(), currentBossBullets3.end(), currentBossBullets3[i]));
}

void Boss::update(Level1* world){
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	for (int i = 0; i < currentBossBullets.size(); i++){
		if (currentBossBullets[i]->getRemove()){
			deleteBossBullet(world, i);
		}
		else currentBossBullets[i]->update();
	}
	if (bossBulletCounter % (SECOND) == 0){
		BossBullet *bossBullet = BossBullet::createBossBullet();
		currentBossBullets.push_back(bossBullet);
		bossBullet->setPosition(getPosition().x, getPosition().y);
		world->addChild(bossBullet, 3);
		bossBulletCounter = 0;
	}
	if (lives <= 40){
		for (int i = 0; i < currentBossBullets2.size(); i++){
			if (currentBossBullets2[i]->getRemove()){
				deleteBossBullet2(world, i);
			}
			else currentBossBullets2[i]->update2();
		}

		if (bossBulletCounter2 % (SECOND * 2) == 0){
			BossBullet *bossBullet2 = BossBullet::createBossBullet2();
			currentBossBullets2.push_back(bossBullet2);
			bossBullet2->setPosition(getPosition().x, getPosition().y + 20);
			world->addChild(bossBullet2, 3);
			bossBulletCounter2 = 0;
		}
	}

	if (lives <= 25){
		for (int i = 0; i < currentBossBullets3.size(); i++){
			if (currentBossBullets3[i]->getRemove()){
				deleteBossBullet3(world, i);
			}
			else currentBossBullets3[i]->update3();
		}
		if (bossBulletCounter3 % (SECOND * 2) == 0){
			BossBullet *bossBullet3 = BossBullet::createBossBullet3();
			currentBossBullets3.push_back(bossBullet3);
			bossBullet3->setPosition(getPosition().x, getPosition().y);
			world->addChild(bossBullet3, 3);
			bossBulletCounter3 = 0;
		}
	}
	if (moving) //check if moving
	{
		if (direction == 0) //check if going left
		{
			setPosition(getPositionX() - 2, s.height - 150);
		}
		else if (direction == 1)  //right
		{
			setPosition(getPositionX() + 2, s.height - 150);
		}
	}

	bossBulletCounter++;
	bossBulletCounter2++;
	bossBulletCounter3++;
}

float Boss::getLives(){
	return lives;
}

void Boss::loseLives(){
	lives--;
}

void Boss::idle(){
	moving = false;
}

void Boss::initBoss(){
	lives = 50;
}