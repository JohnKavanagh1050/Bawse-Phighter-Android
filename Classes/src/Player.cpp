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

void Player::move(int directionParam)
{
	direction = directionParam;
	moving = true;
}

void Player::update()
{
	if (moving) //check if moving
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
}

void Player::idle()
{
	moving = false;
}

void Player::initPlayer(){

}


