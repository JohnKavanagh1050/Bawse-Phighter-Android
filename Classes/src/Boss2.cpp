#include "Boss2.h"

USING_NS_CC;

Boss2 * Boss2::create()
{
	Boss2 * boss2 = new Boss2();
	if (boss2 && boss2->initWithFile("GameScreen/boss2.png", Rect(0, 0, 278, 398)))
	{
		//Create and run animation
		Vector<SpriteFrame*> animFrames(4);
		char str[100] = { 0 };
		for (int i = 0; i < 4; i++)
		{
			sprintf(str, "GameScreen/bos2.png");
			auto frame = SpriteFrame::create(str, Rect(278 * i, 0, 278, 398));
			//auto frame = SpriteFrame::create(str, Rect(201 * i, 206, 201, 206)); //we assume that the sprites' dimentions are 30x30 rectangles.
			animFrames.pushBack(frame);
		}
		auto animation = CCAnimation::createWithSpriteFrames(animFrames, 0.15f, 100000);
		auto animate = CCAnimate::create(animation);
		cocos2d::Size size(278, 398);
		auto bossBody = PhysicsBody::createBox(size);
		bossBody->setCollisionBitmask(0x000005);
		bossBody->setContactTestBitmask(true);
		bossBody->setTag(50);
		boss2->setPhysicsBody(bossBody);
		boss2->runAction(animate);
		boss2->autorelease();
		boss2->initBoss2();
		boss2->setTag(50);
		return boss2;
	}

	CC_SAFE_DELETE(boss2);
	return NULL;
}

void Boss2::move(int directionParam)
{
	direction = directionParam;
	moving = true;
}

/*bool Boss::Hit()
{
hit = true;
}*/

std::vector<BossBullet*> Boss2::getBullets()
{
	return currentBossBullets;
}

void Boss2::deleteBossBullet(Level1* world, int i)
{
	world->removeChild(currentBossBullets[i]);
	currentBossBullets.erase(std::remove(currentBossBullets.begin(), currentBossBullets.end(), currentBossBullets[i]));
}

void Boss2::update(Level1* world)
{
	for (int i = 0; i < currentBossBullets.size(); i++){
		currentBossBullets[i]->update();
		if (currentBossBullets[i]->getRemove()){
			deleteBossBullet(world, i);
			currentBossBullets.erase(std::remove(currentBossBullets.begin(), currentBossBullets.end(), currentBossBullets[i]));
		}
	}
	if (bossCounter % (SECOND) == 0){
		BossBullet *bossBullet = BossBullet::createBossBullet();
		currentBossBullets.push_back(bossBullet);
		bossBullet->setPosition(getPosition().x, getPosition().y);
		world->addChild(bossBullet, 5);
		bossCounter = 0;
	}

	if (moving) //check if moving
	{
		if (direction == 0) //check if going left
		{
			this->setPositionX(this->getPositionX() - 2);
		}
		else if (direction == 1)  //right
		{
			this->setPositionX(this->getPositionX() + 2);
		}
	}

	bossCounter++;

	return;
}

float Boss2::getLives(){
	return lives;
}

void Boss2::loseLives(){
	lives--;
}

void Boss2::idle()
{
	moving = false;
}

void Boss2::initBoss2(){
	lives = 5;
}