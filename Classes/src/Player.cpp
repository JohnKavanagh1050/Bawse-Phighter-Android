#include "Player.h"

Player * Player::create()
{
	Player * player = new Player();
	if (player && player->initWithFile("GameScreen/player.png"))
	{
		player->initPlayer();
		return player;
	}
}

void Player::move(float x ,float y)
{
	dirX = x;
	dirY = y;
	moving = true;
}

/*bool Player::Hit()
{
	hit = true;
}*/

float Player::getLives(){
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
	for (int i = 0; i < currentPlayerBullets.size(); i++){
		currentPlayerBullets[i]->updatePlayerBullet();
		if (currentPlayerBullets[i]->getRemove()){
			deletePlayerBullet(world, i);
		}
	}
	if (counter % (SECOND) == 0){
		Bullet *playerBullet = Bullet::createPlayerBullet();
		currentPlayerBullets.push_back(playerBullet);
		playerBullet->setPosition(getPosition().x, getPosition().y);
		world->addChild(playerBullet, 5);
		
		counter = 0;
	}

	if (moving) //check if moving
	{
		setPositionX(getPosition().x + dirX * speed);
		setPositionY(getPosition().y + dirY * speed) ;
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
}
