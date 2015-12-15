#include "MainMenuScene.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = MainMenu::create();

	scene->addChild(layer);

	return scene;
}

bool MainMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto menuTitle =
		MenuItemImage::create("MainMenuScreen/Game_Title.png",
		"MainMenuScreen/Game_Title.png");
	auto playItem =
		MenuItemImage::create("MainMenuScreen/Play_Button.png",
		"MainMenuScreen/Play_Button(Click).png",
		CC_CALLBACK_1(MainMenu::activateGameScene, this));
	auto upgradeItem =
		MenuItemImage::create("MainMenuScreen/Upgrade_Button.png",
		"MainMenuScreen/Upgrade_Button(Click).png",
	CC_CALLBACK_1(MainMenu::activateUpgradeScene, this));
	auto exitItem =
		MenuItemImage::create("MainMenuScreen/Exit_Button.png",
		"MainMenuScreen/Exit_Button(Click).png",
		CC_CALLBACK_1(MainMenu::exitGame, this));
	auto menu = Menu::create(menuTitle, playItem, upgradeItem, exitItem, NULL);

	// Returns visible size of OpenGL window in points.
	Size visibleSize = Director::getInstance()->getVisibleSize();
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 20);
	this->addChild(menu);

	return true;
}

void MainMenu::activateGameScene(Ref * pSender)
{
	auto scene = GameScreen::createScene();
	Director::getInstance()->replaceScene(scene);
}

void MainMenu::activateUpgradeScene(Ref * pSender)
{
	auto scene = UpgradeMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}

void MainMenu::exitGame(Ref* pSender)
{
	CCDirector::sharedDirector()->end();
}