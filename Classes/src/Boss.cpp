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
	if (boss && boss->initWithFile("GameScreen/ss_boss1.png", Rect(201, 206, 201, 206)))
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
			auto frame = SpriteFrame::create(str, Rect((201 * scaleFactor) * i, 206 * scaleFactor, 201 * scaleFactor, 206 * scaleFactor)); 
			//auto frame = SpriteFrame::create(str, Rect(201 * i, 206, 201, 206)); //we assume that the sprites' dimentions are 30x30 rectangles.
			animFrames.pushBack(frame);
		}
		auto animation = CCAnimation::createWithSpriteFrames(animFrames, 0.15f, 100000);
		auto animate = CCAnimate::create(animation);
		cocos2d::Size size(201, 206);
		auto bossBody = PhysicsBody::createBox(size);
		bossBody->setCollisionBitmask(0x000002);
		bossBody->setContactTestBitmask(true);
		bossBody->setTag(30);
		boss->setPhysicsBody(bossBody);
		boss->runAction(animate);
		boss->autorelease();
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
	lives = 5;
}