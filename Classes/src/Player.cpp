#include "Player.h"
USING_NS_CC;

Player * Player::create()
{
	Player * player = new Player();
	if (player && player->initWithFile("GameScreen/ninja.png", Rect(0, 0, 66, 99)))
	{
		//Create and run animation
		Vector<SpriteFrame*> animFrames(3);
		char str[100] = { 0 };
		for (int i = 0; i < 3; i++)
		{
			sprintf(str, "GameScreen/ninja.png");
			auto frame = SpriteFrame::create(str, Rect(66* i, 99, 66, 99)); 
			animFrames.pushBack(frame);
		}
		auto animation = CCAnimation::createWithSpriteFrames(animFrames, 0.15f, 100000);
		auto animate = CCAnimate::create(animation);
		//make body for collisions
		cocos2d::Size size(66, 99);
		auto playerBody = PhysicsBody::createBox(size);
		playerBody->setCollisionBitmask(0x000002);
		playerBody->setContactTestBitmask(true);
		playerBody->setTag(20);
		player->setPhysicsBody(playerBody);

		player->runAction(animate);
		player->initPlayer();
		player->setTag(20);
		return player;
	}
	CC_SAFE_DELETE(player);
	return NULL;
}

void Player::move(float x ,float y)
{
	dirX = x;
	dirY = y;
	moving = true;
}

float Player::getLives(){
	return lives;
}

float Player::setLives(){
	lives = 10;
	return lives;
}

void Player::deletePlayerBullet(Level1* world, int i)
{
	world->removeChild(currentPlayerBullets[i]);
	currentPlayerBullets.erase(std::remove(currentPlayerBullets.begin(), currentPlayerBullets.end(), currentPlayerBullets[i]));
}

std::vector<Bullet*> Player::getBullets()
{
	return currentPlayerBullets;
}

void Player::update(Level1* world)
{	
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	for (int i = 0; i < currentPlayerBullets.size(); i++){
		if (currentPlayerBullets[i]->getRemove()){
			deletePlayerBullet(world, i);
		}
		else currentPlayerBullets[i]->updatePlayerBullet();
	}
	if (counter % (SECOND) == 0){
		Bullet *playerBullet = Bullet::createPlayerBullet();
		currentPlayerBullets.push_back(playerBullet);
		playerBullet->setPosition(getPosition().x, getPosition().y);
		world->addChild(playerBullet, 3);
		
		counter = 0;
	}

	//health bars 
	Vec2 vertices[] =
	{
		Vec2(0, 10),
		Vec2(100, 10),
		Vec2(100, 0),
		Vec2(0, 0)
	};
	rectWithBorder->drawPolygon(vertices, 4, Color4F(1.0f, 0.0f, 0.0f, 1), 3, Color4F(0.0f, 0.0f, 0.0f, 0));

	Vec2 vertices2[] =
	{
		Vec2(0, 10),
		Vec2((10 * lives), 10),
		Vec2((10 * lives), 0),
		Vec2(0, 0)
	};
	rectWithBorder2->drawPolygon(vertices2, 4, Color4F(0.0f, 1.0f, 0.0f, 1), 3, Color4F(0.0f, 0.0f, 0.0f, 1));

	if (moving) //check if moving
	{
		setPositionX(getPosition().x + dirX * speed);
		setPositionY(getPosition().y + dirY * speed) ;
	}
	//boundaries for level 1
	if (getPositionX() >= s.width - 50)
	{
		setPosition(s.width - 50, getPositionY());
	}

	if (getPositionY() >= s.height - 220)
	{
		setPosition(getPositionX(), s.height - 220);
	}
	if (getPositionX() <= 30)
	{
		setPosition(30, getPositionY());
	}

	if (getPositionY() <= 30)
	{
		setPosition(getPositionX(), 30);
	}
	//keep player facing upwards 
	setRotation(0);
	counter++;
}

void Player::updateLevel2(Level1* world)
{
	//health bars 
	Vec2 vertices[] =
	{
		Vec2(0, 10),
		Vec2(100, 10),
		Vec2(100, 0),
		Vec2(0, 0)
	};
	rectWithBorder->drawPolygon(vertices, 4, Color4F(1.0f, 0.0f, 0.0f, 1), 3, Color4F(0.0f, 0.0f, 0.0f, 0));
	Vec2 vertices2[] =
	{
		Vec2(0, 10),
		Vec2((10 * lives), 10),
		Vec2((10 * lives), 0),
		Vec2(0, 0)
	};
	rectWithBorder2->drawPolygon(vertices2, 4, Color4F(0.0f, 1.0f, 0.0f, 1), 3, Color4F(0.0f, 0.0f, 0.0f, 1));

	CCSize s = CCDirector::sharedDirector()->getWinSize();

	//setRotation(rotation);
	for (int i = 0; i < currentPlayerBullets.size(); i++){
		if (currentPlayerBullets[i]->getRemove()){
			deletePlayerBullet(world, i);
			//currentBossBullets.erase(std::remove(currentBossBullets.begin(), currentBossBullets.end(), currentBossBullets[i]));
		}
		else currentPlayerBullets[i]->updatePlayerBulletLevel2();
	}
	if (counter % (SECOND) == 0){
		Bullet *playerBullet = Bullet::createPlayerBullet();
		currentPlayerBullets.push_back(playerBullet);
		playerBullet->setPosition(getPosition().x, getPosition().y);
		world->addChild(playerBullet, 3);

		counter = 0;
	}

	if (moving) //check if moving
	{
		setPositionX(getPosition().x + dirX * speed);
		setPositionY(getPosition().y + dirY * speed);
		
	}

	if (getPositionX() >= s.width - 50)
	{ 
		setPosition(s.width - 50, getPositionY());
	}

	if (getPositionY() >= s.height - 50)
	{
		setPosition(getPositionX(), s.height - 50);
	}
	if (getPositionX() <= 30)
	{
		setPosition(30, getPositionY());
	}

	if (getPositionY() <= 30)
	{
		setPosition(getPositionX(), 30);
	}
	counter++;
}


void Player::loseLives(){
	lives--;
}

void Player::idle()
{
	moving = false;
}

void Player::initPlayer(){
	speed = 5.f;
	dirX = dirY = 0;
	lives = 10;

	rectWithBorder = DrawNode::create();
	Vec2 vertices[] =
	{
		Vec2(0, 10),
		Vec2(100, 10),
		Vec2(100, 0),
		Vec2(0, 0)
	};
	rectWithBorder->setPosition(getPositionX(), getPositionY() - 5);
	rectWithBorder->drawPolygon(vertices, 4, Color4F(1.0f, 0.0f, 0.0f, 1), 3, Color4F(0.0f, 0.0f, 0.0f, 0));
	addChild(rectWithBorder);

	rectWithBorder2 = DrawNode::create();
	Vec2 vertices2[] =
	{
		Vec2(0, 10),
		Vec2((10 * lives), 10),
		Vec2((10 * lives), 0),
		Vec2(0, 0)
	};
	rectWithBorder2->setPosition(getPositionX(), getPositionY() - 5);
	rectWithBorder2->drawPolygon(vertices2, 4, Color4F(0.0f, 1.0f, 0.0f, 1), 3, Color4F(0.0f, 0.0f, 0.0f, .5));
	addChild(rectWithBorder2);
}
