#include "GameOverScene.h"

USING_NS_CC;

Scene* GameOver::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = GameOver::create();

	scene->addChild(layer);

	return scene;
}

bool GameOver::init()
{
	auto menuTitle =
		MenuItemImage::create("GameOverScreen/Game_Over.png",
		"GameOverScreen/Game_Over.png");
	auto retryItem =
		MenuItemImage::create("GameOverScreen/Retry_Button.png",
		"GameOverScreen/Retry_Button(Click).png",
		CC_CALLBACK_1(GameOver::activateGameScene, this));
	auto mainMenuItem =
		MenuItemImage::create("GameOverScreen/Menu_Button.png",
		"GameOverScreen/Menu_Button(Click).png",
		CC_CALLBACK_1(GameOver::activateMainMenuScene, this));
	auto menu = Menu::create(menuTitle, retryItem, mainMenuItem,
		NULL);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 20);
	this->addChild(menu);

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("iamdeath.wav");

	return true;
}

void GameOver::activateGameScene(cocos2d::Ref *pSender)
{
	auto scene = Level1::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameOver::activateMainMenuScene(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(TransitionSlideInB::create(1, scene));
}