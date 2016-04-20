#include "GameScene.h"

USING_NS_CC;

Scene* Level1::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	auto layer = Level1::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

	scene->addChild(layer);

	return scene;
}

bool Level1::init()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(Level1::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(Level1::onTouchEnded, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	auto pauseItem =
		MenuItemImage::create("GameScreen/Pause_Button.png",
		"GameScreen/Pause_Button(Click).png",
		CC_CALLBACK_1(Level1::activatePauseScene, this));

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	CCSize s = CCDirector::sharedDirector()->getWinSize();

	pauseItem->setPosition(Point(pauseItem->getContentSize().width -
		(pauseItem->getContentSize().width / 4) + origin.x,
		visibleSize.height - pauseItem->getContentSize().height +
		(pauseItem->getContentSize().width / 4) + origin.y));

	auto menu = Menu::create(pauseItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	CCLabelTTF* ttf1 = CCLabelTTF::create("Level 1", "Ninja Penguin.ttf", 30, CCSizeMake(245, 32), kCCTextAlignmentCenter);
	
	switch (level)
	{
	case 'A':
		addBackGroundSprite(visibleSize, origin);

		boss = Boss::create();
		boss->setPosition(Vec2(300, 350));
		this->addChild(boss, 5);

		player = Player::create();
		player->setPosition(Vec2(100, 70));
		this->addChild(player, 5);

		ttf1->setPosition(Vec2(s.width / 2, s.height - 30));
		ttf1->setColor(Color3B(0, 0, 0));
		this->addChild(ttf1, 4);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("GameMusic.wav", true);
		break;
	case 'B':
		auto mySprite = Sprite::create("GameScreen/Background2.png");
		mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
		mySprite->setScale(1,1);
		this->addChild(mySprite, -1);

		boss2 = Boss2::create();
		this->addChild(boss2, 5);
		boss2->setPosition(Vec2(s.width / 2, s.height / 2));

		CCLabelTTF* ttf2 = CCLabelTTF::create("Level 2", "Ninja Penguin.ttf", 30, CCSizeMake(245, 32), kCCTextAlignmentCenter);
		ttf2->setPosition(Vec2(s.width / 2, s.height - 30));
		ttf2->setColor(Color3B(0, 0, 0));
		this->addChild(ttf2, 4);
		break;
	}

	this->scheduleUpdate();
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Level1::onContactBegin, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	return true;
}

void Level1::activatePauseScene(Ref *pSender)
{
	auto scene = PauseMenu::createScene();
	//auto scene = GameOver::createScene();
	Director::getInstance()->pushScene(scene);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic("GameMusic.wav");
}

void Level1::activateMainMenuScene(cocos2d::Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Level1::activateGameOverScene(Ref *pSender)
{
	auto scene = GameOver::createScene();
	Director::getInstance()->replaceScene(scene);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic("GameMusic.wav");
}

void Level1::activateGameCompleteScene(Ref *pSender)
{
	auto scene = GameComplete::createScene();
	Director::getInstance()->replaceScene(scene);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic("GameMusic.wav");
}

bool Level1::onTouchBegan(Touch *touch, Event *event)
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

void Level1::onTouchEnded(Touch *touch, Event *event)
{
	player->idle();
}

void Level1::addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin)
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();
	auto backgroundSprite = Sprite::create(ptr->m_backgroundTextureFile);
	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
	this->addChild(backgroundSprite, -1);
}

void Level1::update(float dt)
{
	//switch statements to update different levels
	switch (level)
	{
	case 'A':
		//updates all enemy and player logic
		player->update(this);
		boss->update(this);
		//checkBoundaries();

		/*currentPlayerBullets = player->getBullets();
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
		//checks every bullet for collisions
		for (int i = 0; i < currentPlayerBullets.size(); i++){
		playerBulletRect = CCRectMake(currentPlayerBullets[i]->getPosition().x - (currentPlayerBullets[i]->getContentSize().width / 2),
		currentPlayerBullets[i]->getPosition().y - (currentPlayerBullets[i]->getContentSize().height / 2),
		currentPlayerBullets[i]->getContentSize().width, currentPlayerBullets[i]->getContentSize().height);
		if (bossRect.intersectsRect(playerBulletRect)){
		player->deletePlayerBullet(this, i);
		boss->loseLives();
		if (boss->getLives() <= 0){
		activateGameScene2(this);
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
		}*/

		//boss movement
		if (boss->getPosition().x > player->getPositionX())
		{
			if (boss->getPosition().x - player->getPositionX() >= 150){
				boss->move(0); // param '0' for left
			}
		}
		if (boss->getPosition().x < player->getPositionX())
		{
			if (boss->getPosition().x - player->getPositionX() <= -150){
				boss->move(1); // param '1' for right
			}
		}
		break;
	case 'B':
		//updates all enemy2 and player logic
		player->updateLevel2(this);
		boss2->update(this);
		break;
	case 'C':
		break;
	}
}

bool Level1::onContactBegin(cocos2d::PhysicsContact &contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	if (nodeA && nodeB)
	{
		//bullet and boss collision
		//if bullet
		if (nodeA->getTag() == 10)
		{
			//if boss
			if (nodeB->getTag() == 30)
			{
				nodeA->removeFromParentAndCleanup(true);
				boss->loseLives();
				if (boss->getLives() <= 0){
					//start level 2 switch statement
					level = 'B';
					//removes boss1
					nodeB->removeFromParentAndCleanup(true);
					//re-initilize level
					init();
				}
			}
			//if bossbullet
			else if (nodeB->getTag() == 40)
			{
				nodeA->removeFromParentAndCleanup(true);
				nodeB->removeFromParentAndCleanup(true);
			}
			//if boss2
			else if (nodeB->getTag() == 50)
			{
				nodeA->removeFromParentAndCleanup(true);
				boss2->loseLives();
				if (boss2->getLives() <= 0){
					activateGameCompleteScene(this);
				}
			}
			//if bossbullet2
			else if (nodeB->getTag() == 60)
			{
				nodeA->removeFromParentAndCleanup(true);
				nodeB->removeFromParentAndCleanup(true);
			}
			//if bossbullet3
			else if (nodeB->getTag() == 70)
			{
				nodeA->removeFromParentAndCleanup(true);
				nodeB->removeFromParentAndCleanup(true);
			}
		}
		//bullet and boss collision
		//if boss
		else if (nodeA->getTag() == 30)
		{
			// if bullet
			if (nodeB->getTag() == 10)
			{
				nodeB->removeFromParentAndCleanup(true);
				boss->loseLives();
				if (boss->getLives() <= 0){
					level = 'B';
					nodeA->removeFromParentAndCleanup(true);
					init();
				}
			}
		}
		//bullet and boss collision
		//if boss2
		else if (nodeA->getTag() == 50)
		{
			//if player
			if (nodeB->getTag() == 10)
			{
				nodeB->removeFromParentAndCleanup(true);
				boss2->loseLives();
				if (boss2->getLives() <= 0){
					activateGameCompleteScene(this);
				}
			}
		}
		//player and bossbullet collision
		//if bossbullet1
		else if (nodeA->getTag() == 40)
		{
			//if player
			if (nodeB->getTag() == 20)
			{
				nodeA->removeFromParentAndCleanup(true);
				player->loseLives();
				if (player->getLives() <= 0){
					activateGameOverScene(this);
				}
			}
			//if bullet
			else if (nodeB->getTag() == 10)
			{
				nodeB->removeFromParentAndCleanup(true);
				nodeA->removeFromParentAndCleanup(true);
			}
		}
		//player and bossbullet2 collision
		//if bossbullet1
		else if (nodeA->getTag() == 60)
		{
			//if player
			if (nodeB->getTag() == 20)
			{
				nodeA->removeFromParentAndCleanup(true);
				player->loseLives();
				if (player->getLives() <= 0){
					activateGameOverScene(this);
				}
			}
			//if bullet
			else if (nodeB->getTag() == 10)
			{
				nodeB->removeFromParentAndCleanup(true);
				nodeA->removeFromParentAndCleanup(true);
			}
		}
		//player and bossbullet collision
		//if bossbullet3
		else if (nodeA->getTag() == 70)
		{
			//if player
			if (nodeB->getTag() == 20)
			{
				nodeA->removeFromParentAndCleanup(true);
				player->loseLives();
				if (player->getLives() <= 0){
					activateGameOverScene(this);
				}
				
			}
			//if bullet
			else if (nodeB->getTag() == 10)
			{
				nodeB->removeFromParentAndCleanup(true);
				nodeA->removeFromParentAndCleanup(true);
			}
		}
		//player and bossbullet collision
		//if player
		else if (nodeA->getTag() == 20)
		{
			//if bossbullet
			if (nodeB->getTag() == 40)
			{
				nodeB->removeFromParentAndCleanup(true);
				player->loseLives();
				if (player->getLives() <= 0){
					//removes bossbullet
					activateGameOverScene(this);
				}
			}
			//if bossbullet2
			else if (nodeB->getTag() == 60)
			{
				nodeB->removeFromParentAndCleanup(true);
				player->loseLives();
				if (player->getLives() <= 0){
					activateGameOverScene(this);
				}
			}
			//if bossbullet3
			else if (nodeB->getTag() == 70)
			{
				nodeB->removeFromParentAndCleanup(true);
				player->loseLives();
				if (player->getLives() <= 0){
					activateGameOverScene(this);
				}
			}
		}
	}
	return true;
}