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

void Boss::update()
{
	if (moving) //check if moving
	{
		if (direction == 0) //check if going left
		{
			this->setPositionX(this->getPositionX() - 3);
		}
		else if (direction == 1)  //right
		{
			this->setPositionX(this->getPositionX() + 3);
		}
	}
}

void Boss::idle()
{
	moving = false;
}

void Boss::initBoss(){
	//speed = 5.f;
	//dirX = dirY = 0;
}
