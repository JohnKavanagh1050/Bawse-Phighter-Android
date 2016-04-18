#include "Boss.h"

USING_NS_CC;

typedef struct tagResource
{
	cocos2d::Size size;
	char directory[100];
} Resource;

Boss * Boss::create()
{
	Boss * boss = new Boss();
	if (boss && boss->initWithFile("GameScreen/ss_boss1.png", Rect(134, 137, 134, 137)))
	{
		// Landscape config.
		// 800x480 = Normal screen, WVGA 
		static Resource smallResource = { cocos2d::Size(800, 480), "sd" };
		// 1280x800 = Extra large screen, WXGA, medium density screen (160)
		static Resource mediumResource = { cocos2d::Size(1280, 800), "hd" };
		// 1900x1200 = WUXGA, Devices with such as Nexus 7, Nvidia Shield.
		static Resource largeResource = { cocos2d::Size(1920, 1200), "shd" };

		static cocos2d::Size designResolutionSize = smallResource.size;

		CCSize s = CCDirector::sharedDirector()->getWinSize();

		std::vector<std::string> searchPaths;
		float scaleFactor = 1.0f;

		if (s.height > mediumResource.size.height)
		{
			scaleFactor = largeResource.size.height / designResolutionSize.height;
		}

		//Create and run animation
		Vector<SpriteFrame*> animFrames(7);
		char str[100] = { 0 };
		for (int i = 0; i < 7; i++)
		{
			sprintf(str, "GameScreen/ss_boss1.png");
			auto frame = SpriteFrame::create(str, Rect((134 * scaleFactor) * i, 137 * scaleFactor, 134 * scaleFactor, 137 * scaleFactor)); 
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

void Boss::move(int directionParam)
{
	direction = directionParam;
	moving = true;
}

/*bool Boss::Hit()
{
	hit = true;
}*/

std::vector<Missile*> Boss::getMissiles()
{
	return currentMissiles;
}

std::vector<BossBullet*> Boss::getBullets()
{
	return currentBossBullets;
}

std::vector<BossBullet*> Boss::getBullets2()
{
	return currentBossBullets2;
}

void Boss::deleteBossBullet2(Level1* world, int i)
{
	world->removeChild(currentBossBullets2[i]);
	currentBossBullets2.erase(std::remove(currentBossBullets2.begin(), currentBossBullets2.end(), currentBossBullets2[i]));
}

void Boss::deleteMissile(Level1* world, int i)
{
	world->removeChild(currentMissiles[i]);
	currentMissiles.erase(std::remove(currentMissiles.begin(), currentMissiles.end(), currentMissiles[i]));
}

void Boss::deleteBossBullet(Level1* world, int i)
{
	world->removeChild(currentBossBullets[i]);
	currentBossBullets.erase(std::remove(currentBossBullets.begin(), currentBossBullets.end(), currentBossBullets[i]));
}

void Boss::update(Level1* world)
{
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	for (int i = 0; i < currentBossBullets.size(); i++){
		if (currentBossBullets[i]->getRemove()){
			deleteBossBullet(world, i);
		}
		else currentBossBullets[i]->update();
	}
	if (bossCounter % (SECOND) == 0){
		BossBullet *bossBullet = BossBullet::createBossBullet();
		currentBossBullets.push_back(bossBullet);
		bossBullet->setPosition(getPosition().x, getPosition().y);
		world->addChild(bossBullet, 3);
		bossCounter = 0;
	}
	if (lives <= 25){
		for (int i = 0; i < currentMissiles.size(); i++){
			if (currentMissiles[i]->getRemove()){
				deleteMissile(world, i);
			}
			else currentMissiles[i]->update();
		}

		if (missileCounter % (SECOND * 2) == 0){
			Missile *missile = Missile::createMissile();
			currentMissiles.push_back(missile);
			missile->setPosition(getPosition().x, getPosition().y + 20);
			world->addChild(missile, 3);
			missileCounter = 0;
		}
	}

	if (lives <= 10){
		for (int i = 0; i < currentBossBullets2.size(); i++){
			if (currentBossBullets2[i]->getRemove()){
				deleteBossBullet2(world, i);
			}
			else currentBossBullets2[i]->update2();
		}
		if (missile2Counter % (SECOND * 2) == 0){
			BossBullet *missile2 = BossBullet::createBossBullet2();
			currentBossBullets2.push_back(missile2);
			missile2->setPosition(getPosition().x, getPosition().y);
			world->addChild(missile2, 3);
			missile2Counter = 0;
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

	bossCounter++;
	missileCounter++;
	missile2Counter++;
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