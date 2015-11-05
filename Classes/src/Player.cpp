#include "GameScene.h"
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

void Player::moveRL(int directionParam)
{
	direction = directionParam;
	movingRL = true;
}

void Player::moveUD(int directionParam)
{
	direction = directionParam;
	movingUD = true;
}

void Player::update()
{
	if (movingRL) //check if moving
	{
		if (direction == 0) //check if going left
		{
			this->setPositionX(this->getPositionX() - 5);
		}
		if (direction == 1)
		{
			this->setPositionX(this->getPositionX() + 5);
		}
	}
	if (movingUD) //check if moving
	{
		if (direction == 2)
		{
			this->setPositionY(this->getPositionY() + 5);
		}
		 if (direction == 3)
		{
			this->setPositionY(this->getPositionY() - 5);
		}
	}
}

void Player::initPlayer(){

}


