#include "HealthBar.h"

HealthBar * HealthBar::create()
{
	HealthBar * healthBar = new HealthBar();
	if (healthBar && healthBar->initWithFile("GameScreen/bullet.png"))
	{
		healthBar->autorelease();
		return healthBar;
	}

	CC_SAFE_DELETE(healthBar);
	return NULL;
}

void HealthBar::update()
{
	
}