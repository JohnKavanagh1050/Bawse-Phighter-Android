#include "Boss.h"

Boss * Boss::create()
{
	Boss * boss = new Boss();
	if (boss && boss->initWithFile("GameScreen/boss.png"))
	{
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

void Boss::Hit()
{
	hit = true;
}

void Boss::deleteBossBullet(GameScreen* world, int i)
{
	world->removeChild(currentBossBullets[i]);
}

void Boss::update(GameScreen* world )
{
	for (int i = 0; i < currentBossBullets.size(); i++){
		currentBossBullets[i]->update();
		if (currentBossBullets[i]->getRemove()){
			deleteBossBullet(world, i);
		}
	}
	if (bossCounter % (SECOND) == 0){
		BossBullet *bossBullet = BossBullet::createBossBullet();
		currentBossBullets.push_back(bossBullet);
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

void Boss::idle()
{
	moving = false;
}

void Boss::initBoss(){
	lives = 100;
}

