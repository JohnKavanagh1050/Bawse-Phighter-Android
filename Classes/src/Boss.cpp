#include "GameScene.h"
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
	
}

void Boss::idle()
{
	moving = false;
}

void Boss::initBoss(){

}

