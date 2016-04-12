#include "GameScene2.h"

USING_NS_CC;

Scene* Level2::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = Level2::create();

	scene->addChild(layer);

	return scene;
}

bool Level2::init()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(Level2::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(Level2::onTouchEnded, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	this->scheduleUpdate();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	CCSize s = CCDirector::sharedDirector()->getWinSize();

	CCLabelTTF* ttf1 = CCLabelTTF::create("Level 2", "Ninja Penguin.ttf", 30, CCSizeMake(245, 32), kCCTextAlignmentCenter);
	ttf1->setPosition(Vec2(s.width / 2, s.height - 30));
	ttf1->setColor(Color3B(0, 0, 0));
	this->addChild(ttf1, 4);

	auto pauseItem = MenuItemImage::create("GameScreen/Pause_Button.png",
		"GameScreen/Pause_Button(Click).png", CC_CALLBACK_1(Level2::activatePauseScene, this));

	pauseItem->setPosition(Point(pauseItem->getContentSize().width - (pauseItem->getContentSize().width / 4) + origin.x,
		visibleSize.height - pauseItem->getContentSize().height + (pauseItem->getContentSize().width / 4) + origin.y));

	auto menu = Menu::create(pauseItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	//boss2 = Boss2::create();
	//boss2->setPosition(Vec2(s.width / 2, s.height / 2));
	//this->addChild(boss2, 5);

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("GameMusic.wav", true);

	return true;
}

void Level2::activatePauseScene(Ref *pSender)
{
	//auto scene = PauseMenu::createScene();
	auto scene = GameOver::createScene();
	Director::getInstance()->pushScene(scene);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic("GameMusic.wav");
}

void Level2::activateMainMenuScene(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Level2::activateGameOverScene(Ref *pSender)
{
	auto scene = GameOver::createScene();
	Director::getInstance()->replaceScene(scene);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic("GameMusic.wav");
}

bool Level2::onTouchBegan(Touch *touch, Event *event)
{
	return true;
}

void Level2::onTouchEnded(Touch *touch, Event *event)
{

}

void Level2::addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin)
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();
	auto backgroundSprite = Sprite::create(ptr->m_backgroundTextureFile);
	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
	this->addChild(backgroundSprite, -1);
}

void Level2::update(float dt)
{
	
}