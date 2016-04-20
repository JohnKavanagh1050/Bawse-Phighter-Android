#include "PauseScene.h"

USING_NS_CC;

Scene* PauseMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = PauseMenu::create();

	scene->addChild(layer);

	return scene;
}

bool PauseMenu::init()
{
	auto menuTitle =
		MenuItemImage::create("PauseScreen/Game_Paused.png",
		"PauseScreen/Game_Paused.png");
	auto resumeItem =
		MenuItemImage::create("PauseScreen/Resume_Button.png",
		"PauseScreen/Resume_Button(Click).png",
		CC_CALLBACK_1(PauseMenu::resume, this));
	auto retryItem =
		MenuItemImage::create("PauseScreen/Retry_Button.png",
		"PauseScreen/Retry_Button(Click).png",
		CC_CALLBACK_1(PauseMenu::retry, this));
	auto mainMenuItem =
		MenuItemImage::create("PauseScreen/Menu_Button.png",
		"PauseScreen/Menu_Button(Click).png",
		CC_CALLBACK_1(PauseMenu::activateMainMenuScene, this));
	auto menu = Menu::create(menuTitle, resumeItem, retryItem, mainMenuItem,
		NULL);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	//menu->alignItemsVerticallyWithPadding(visibleSize.height / 20);
	menu->alignItemsVertically();
	this->addChild(menu);

	return true;
}

void PauseMenu::resume(Ref *pSender)
{
	Director::getInstance()->popScene();
}

void PauseMenu::activateMainMenuScene(Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(TransitionSlideInB::create(1, scene));
}

void PauseMenu::retry(Ref *pSender)
{
	auto scene = Level1::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}