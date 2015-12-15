#include "Player.h"

Player * Player::create()
{
	Player * player = new Player();
	if (player && player->initWithFile("GameScreen/player.png"))
	{
		player->autorelease();
		player->initPlayer();
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

void Player::update()
{
	if (moving) //check if moving
	{
		setPositionX(getPosition().x + dirX * speed);
		setPositionY(getPosition().y + dirY * speed) ;

		//if (direction == 0) //check if going left
		//{
		//	this->setPositionX(this->getPositionX() - 5);
		//}
		//else if (direction == 1)
		//{
		//	this->setPositionX(this->getPositionX() + 5);
		//}

		//else if (direction == 2) //check if going left
		//{
		//	this->setPositionY(this->getPositionY() - 5);
		//}

		//else if (direction == 3)
		//{
		//	this->setPositionY(this->getPositionY() + 5);
		//}
	}
}

void Player::idle()
{
	moving = false;
}

void Player::initPlayer(){
	speed = 5.f;
	dirX = dirY = 0;
}


