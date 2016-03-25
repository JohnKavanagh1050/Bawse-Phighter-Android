#include "GameScene.h"

USING_NS_CC;

Scene* GameScreen::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = GameScreen::create();

	scene->addChild(layer);

	return scene;
}

bool GameScreen::init()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(GameScreen::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScreen::onTouchEnded, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	this->scheduleUpdate();

	auto pauseItem =
		MenuItemImage::create("GameScreen/Pause_Button.png",
		"GameScreen/Pause_Button(Click).png",
		CC_CALLBACK_1(GameScreen::activatePauseScene, this));

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	pauseItem->setPosition(Point(pauseItem->getContentSize().width -
		(pauseItem->getContentSize().width / 4) + origin.x,
		visibleSize.height - pauseItem->getContentSize().height +
		(pauseItem->getContentSize().width / 4) + origin.y));

	auto menu = Menu::create(pauseItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	addBackGroundSprite(visibleSize, origin);

	player = Player::create();
	player->setPosition(Vec2(100, 70));
	this->addChild(player, 5);

	boss = Boss::create();
	boss->setPosition(Vec2(300, 350));
	this->addChild(boss, 5);

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
		"GameMusic.wav", true);

	return true;
}

void GameScreen::activatePauseScene(Ref *pSender)
{
	//auto scene = PauseMenu::createScene();
	auto scene = GameOver::createScene();
	Director::getInstance()->pushScene(scene);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(
		"GameMusic.wav");
}

void GameScreen::activateMainMenuScene(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameScreen::activateGameOverScene(Ref *pSender)
{
	auto scene = GameOver::createScene();
	Director::getInstance()->replaceScene(scene);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(
		"GameMusic.wav");
}

bool GameScreen::onTouchBegan(Touch *touch, Event *event)
{
	//get location of my touch event for player movement
	float x = touch->getLocation().x - player->getPosition().x;
	float y = touch->getLocation().y - player->getPosition().y;
	float magnitude = sqrtf(powf(x, 2) + powf(y, 2));
	x /= magnitude;
	y /= magnitude;

	player->move(x, y);

	return true;
}

void GameScreen::onTouchEnded(Touch *touch, Event *event)
{
	player->idle();
}

void GameScreen::addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin)
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();
	auto backgroundSprite = Sprite::create(ptr->m_backgroundTextureFile);
	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
	this->addChild(backgroundSprite, -1);
}

void GameScreen::update(float dt)
{
	//updates all enemy and player logic
	player->update(this);
	boss->update(this);

	currentPlayerBullets = player->getBullets();
	currentBossBullets = boss->getBullets();
	//handles collisions with rectangles in cocos
	CCRect playerBulletRect;
	CCRect bossBulletRect;
	CCRect playerRect = CCRectMake(
		player->getPosition().x - (player->getContentSize().width / 2),
		player->getPosition().y - (player->getContentSize().height / 2),
		player->getContentSize().width, player->getContentSize().height);
	CCRect bossRect = CCRectMake(
		boss->getPosition().x - (boss->getContentSize().width / 2),
		boss->getPosition().y - (boss->getContentSize().height / 2),
		boss->getContentSize().width, boss->getContentSize().height);
	for (int i = 0; i < currentPlayerBullets.size(); i++){
		playerBulletRect = CCRectMake(currentPlayerBullets[i]->getPosition().x - (currentPlayerBullets[i]->getContentSize().width / 2),
			currentPlayerBullets[i]->getPosition().y - (currentPlayerBullets[i]->getContentSize().height / 2),
			currentPlayerBullets[i]->getContentSize().width, currentPlayerBullets[i]->getContentSize().height);
		if (bossRect.intersectsRect(playerBulletRect)){
			player->deletePlayerBullet(this, i);
			boss->loseLives();
			if (boss->getLives() <= 0){
				activateMainMenuScene(this);
			}
		}
	}

	for (int i = 0; i < currentBossBullets.size(); i++){
		bossBulletRect = CCRectMake(currentBossBullets[i]->getPosition().x - (currentBossBullets[i]->getContentSize().width / 2),
			currentBossBullets[i]->getPosition().y - (currentBossBullets[i]->getContentSize().height / 2),
			currentBossBullets[i]->getContentSize().width, currentBossBullets[i]->getContentSize().height);
		if (playerRect.intersectsRect(bossBulletRect)){
			boss->deleteBossBullet(this, i);
			player->loseLives();
			if (player->getLives() <= 0){
				activateMainMenuScene(this);
			}
		}
	}
	
	//boss movement
	if (boss->getPosition().x > player->getPositionX())
	{
		boss->move(0); // param '0' for left
	}
	if (boss->getPosition().x < player->getPositionX())
	{
		boss->move(1); // param '1' for right
	}
}
