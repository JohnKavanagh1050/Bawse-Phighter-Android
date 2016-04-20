#include "UpgradeScene.h"

USING_NS_CC;

Scene* UpgradeMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = UpgradeMenu::create();

	scene->addChild(layer);

	return scene;
}

bool UpgradeMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	auto mySprite = Sprite::create("UpgradeScreen/tutorial.png");
	mySprite->setScaleX((s.width / mySprite->getContentSize().width));
	mySprite->setScaleY((s.height / mySprite->getContentSize().height));
	// bottom left
	mySprite->setAnchorPoint(cocos2d::Vec2(0, 0));
	this->addChild(mySprite, -1);

	auto mainMenuItem =
		MenuItemImage::create("UpgradeScreen/Menu_Button.png",
		"UpgradeScreen/Menu_Button(Click).png",
		CC_CALLBACK_1(UpgradeMenu::activateMainMenuScene, this));
	
	auto menu = Menu::create(mainMenuItem, NULL);

	// Returns visible size of OpenGL window in points.
	Size visibleSize = Director::getInstance()->getVisibleSize();
	menu->setPosition(150, s.height - 100);
	this->addChild(menu);

	return true;
}

void UpgradeMenu::activateMainMenuScene(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(TransitionFlipX::create(1, scene));
}