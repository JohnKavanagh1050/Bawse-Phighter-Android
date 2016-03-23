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

	auto upgradeTitle =
		MenuItemImage::create("UpgradeScreen/Upgrade.png",
		"UpgradeScreen/Upgrade.png");

	auto mainMenuItem =
		MenuItemImage::create("UpgradeScreen/Menu_Button.png",
		"UpgradeScreen/Menu_Button(Click).png",
		CC_CALLBACK_1(UpgradeMenu::activateMainMenuScene, this));
	
	auto menu = Menu::create(upgradeTitle, mainMenuItem, NULL);

	// Returns visible size of OpenGL window in points.
	Size visibleSize = Director::getInstance()->getVisibleSize();
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 20);
	this->addChild(menu);

	return true;
}

void UpgradeMenu::activateMainMenuScene(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(TransitionFlipX::create(1, scene));
}