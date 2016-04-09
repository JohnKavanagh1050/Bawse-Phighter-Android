#include "Bullet.h"

USING_NS_CC;

typedef struct tagResource
{
	cocos2d::Size size;
	char directory[100];
} Resource;

Bullet * Bullet::createPlayerBullet()
{
	Bullet * playerBullet = new Bullet();

	if (playerBullet && playerBullet->initWithFile("GameScreen/ninja_star.png", Rect(0, 0, 27, 27)))
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
		Vector<SpriteFrame*> animFrames(3);
		char str[100] = { 0 };
		for (int i = 0; i < 3; i++)
		{
			sprintf(str, "GameScreen/ninja_star.png");
			//auto frame = SpriteFrame::create(str, Rect(64.9 * i, 0, 64.9, 64.9));
			auto frame = SpriteFrame::create(str, Rect((27) * i, 0, 27, 27)); 
			animFrames.pushBack(frame);
		}
		auto animation = CCAnimation::createWithSpriteFrames(animFrames, 0.05f, 100000);
		auto animate = CCAnimate::create(animation);
		//make body for collisions
		cocos2d::Size size(27, 27);
		auto bulletBody = PhysicsBody::createBox(size);
		bulletBody->setCollisionBitmask(0x000003);
		bulletBody->setContactTestBitmask(true);
		bulletBody->setTag(10);
		playerBullet->setPhysicsBody(bulletBody);
		playerBullet->runAction(animate);
		playerBullet->initBullet();
		playerBullet->setTag(10);

		return playerBullet;
	}
	CC_SAFE_DELETE(playerBullet);
	return NULL;
}

void Bullet::animateBullet()
{
	
}

bool Bullet::getRemove(){
	return remove;
}

void Bullet::initBullet(){
	timecounter = timeAlive = 0;
	remove = false;
}

void Bullet::updatePlayerBullet(){
	setPositionY(getPositionY() + 5);

	timecounter++;
	if (timecounter >= 1000){
		remove = true;
	}
}