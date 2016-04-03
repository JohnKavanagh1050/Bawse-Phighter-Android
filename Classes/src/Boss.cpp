#include "Boss.h"

USING_NS_CC;

Boss * Boss::create()
{
	Boss * boss = new Boss();
	if (boss && boss->initWithFile("GameScreen/ss_boss1.png", Rect(201, 206, 201, 206)))
	{
		//Create and run animation
		Vector<SpriteFrame*> animFrames(7);
		char str[100] = { 0 };
		for (int i = 0; i < 7; i++)
		{
			sprintf(str, "GameScreen/ss_boss1.png", i);
			auto frame = SpriteFrame::create(str, Rect(201 * i, 206, 201, 206)); //we assume that the sprites' dimentions are 30x30 rectangles.
			animFrames.pushBack(frame);
		}
		auto animation = Animation::createWithSpriteFrames(animFrames, 0.15f, INFINITE);
		auto animate = Animate::create(animation);
		
		//boss->healthBar->setType = kCCProgressTimerTypeBar;

		boss->runAction(animate);
		boss->autorelease();
		boss->initBoss();
		return boss;
	}

	CC_SAFE_DELETE(boss);
	return NULL;
}

void Boss::move(int directionParam)
{
	direction = directionParam;
	moving = true;
}

/*bool Boss::Hit()
{
	hit = true;
}*/

std::vector<BossBullet*> Boss::getBullets()
{
	return currentBossBullets;
}

void Boss::deleteBossBullet(Level1* world, int i)
{
	world->removeChild(currentBossBullets[i]);
	currentBossBullets.erase(std::remove(currentBossBullets.begin(), currentBossBullets.end(), currentBossBullets[i]));
}

void Boss::update(Level1* world)
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

float Boss::getLives(){
	return lives;
}

void Boss::loseLives(){
	lives--;
}

void Boss::idle()
{
	moving = false;
}

void Boss::initBoss(){
	lives = 50;
}