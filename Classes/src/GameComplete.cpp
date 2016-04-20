#include "GameComplete.h"

USING_NS_CC;

Scene* GameComplete::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = GameComplete::create();

	scene->addChild(layer);

	return scene;
}

bool GameComplete::init()
{
	auto upgradeTitle =
		MenuItemImage::create("GameCompleteScreen/Game_Complete.png",
		"GameCompleteScreen/Game_Complete.png");
	auto retryItem =
		MenuItemImage::create("GameCompleteScreen/Retry_Button.png",
		"GameCompleteScreen/Retry_Button(Click).png",
		CC_CALLBACK_1(GameComplete::activateGameScene, this));
	auto mainMenuItem =
		MenuItemImage::create("GameCompleteScreen/Menu_Button.png",
		"GameCompleteScreen/Menu_Button(Click).png",
		CC_CALLBACK_1(GameComplete::activateMainMenuScene, this));
	auto menu = Menu::create(upgradeTitle, retryItem, mainMenuItem,
		NULL);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 20);
	this->addChild(menu);

	return true;
}

void GameComplete::activateGameScene(cocos2d::Ref *pSender)
{
	auto scene = Level1::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameComplete::activateMainMenuScene(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(TransitionSlideInB::create(1, scene));
}