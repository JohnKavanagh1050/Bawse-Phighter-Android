#include "Boss2.h"

USING_NS_CC;

Boss2 * Boss2::create(){
	Boss2 * boss2 = new Boss2();
	if (boss2 && boss2->initWithFile("GameScreen/boss2.png", Rect(0, 0, 139, 199)))
	{
		//Create and run animation
		Vector<SpriteFrame*> animFrames(4);
		char str[100] = { 0 };
		for (int i = 0; i < 4; i++)
		{
			sprintf(str, "GameScreen/boss2.png");
			auto frame = SpriteFrame::create(str, Rect(139 * i, 0, 139, 199));
			animFrames.pushBack(frame);
		}
		auto animation = CCAnimation::createWithSpriteFrames(animFrames, 0.15f, 100000);
		auto animate = CCAnimate::create(animation);
		cocos2d::Size size(139, 199);
		auto boss2Body = PhysicsBody::createBox(size * 0.75f);
		boss2Body->setCollisionBitmask(0x000005);
		boss2Body->setContactTestBitmask(true);
		boss2Body->setTag(50);
		boss2->setPhysicsBody(boss2Body);
		boss2->runAction(animate);
		boss2->initBoss2();
		boss2->setTag(50);
		return boss2;
	}

	CC_SAFE_DELETE(boss2);
	return NULL;
}

void Boss2::move(int directionParam){
	direction = directionParam;
}

std::vector<Missile*> Boss2::getBullets(){
	return currentBossMissiles;
}

std::vector<Missile*> Boss2::getBullets2(){
	return currentBossMissiles2;
}

std::vector<Missile*> Boss2::getBullets3(){
	return currentBossMissiles3;
}

std::vector<Missile*> Boss2::getBullets4(){
	return currentBossMissiles4;
}

std::vector<Missile*> Boss2::getBullets5(){
	return currentBossMissiles5;
}

std::vector<Missile*> Boss2::getBullets6(){
	return currentBossMissiles6;
}

std::vector<Missile*> Boss2::getBullets7(){
	return currentBossMissiles7;
}

std::vector<Missile*> Boss2::getBullets8(){
	return currentBossMissiles8;
}

std::vector<Missile*> Boss2::getBullets9(){
	return currentBossMissiles9;
}

std::vector<Missile*> Boss2::getBullets10(){
	return currentBossMissiles12;
}

std::vector<Missile*> Boss2::getBullets11(){
	return currentBossMissiles11;
}

std::vector<Missile*> Boss2::getBullets12(){
	return currentBossMissiles12;
}

void Boss2::deleteBossBullet(Level1* world, int i){
	world->removeChild(currentBossMissiles[i]);
	currentBossMissiles.erase(std::remove(currentBossMissiles.begin(), currentBossMissiles.end(), currentBossMissiles[i]));
}

void Boss2::deleteBossBullet2(Level1* world, int i){
	world->removeChild(currentBossMissiles2[i]);
	currentBossMissiles2.erase(std::remove(currentBossMissiles2.begin(), currentBossMissiles2.end(), currentBossMissiles2[i]));
}

void Boss2::deleteBossBullet3(Level1* world, int i){
	world->removeChild(currentBossMissiles3[i]);
	currentBossMissiles3.erase(std::remove(currentBossMissiles3.begin(), currentBossMissiles3.end(), currentBossMissiles3[i]));
}

void Boss2::deleteBossBullet4(Level1* world, int i){
	world->removeChild(currentBossMissiles4[i]);
	currentBossMissiles4.erase(std::remove(currentBossMissiles4.begin(), currentBossMissiles4.end(), currentBossMissiles4[i]));
}

void Boss2::deleteBossBullet5(Level1* world, int i){
	world->removeChild(currentBossMissiles5[i]);
	currentBossMissiles5.erase(std::remove(currentBossMissiles5.begin(), currentBossMissiles5.end(), currentBossMissiles5[i]));
}

void Boss2::deleteBossBullet6(Level1* world, int i){
	world->removeChild(currentBossMissiles6[i]);
	currentBossMissiles6.erase(std::remove(currentBossMissiles6.begin(), currentBossMissiles6.end(), currentBossMissiles6[i]));
}

void Boss2::deleteBossBullet7(Level1* world, int i){
	world->removeChild(currentBossMissiles7[i]);
	currentBossMissiles7.erase(std::remove(currentBossMissiles7.begin(), currentBossMissiles7.end(), currentBossMissiles7[i]));
}

void Boss2::deleteBossBullet8(Level1* world, int i){
	world->removeChild(currentBossMissiles8[i]);
	currentBossMissiles8.erase(std::remove(currentBossMissiles8.begin(), currentBossMissiles8.end(), currentBossMissiles8[i]));
}

void Boss2::deleteBossBullet9(Level1* world, int i){
	world->removeChild(currentBossMissiles9[i]);
	currentBossMissiles9.erase(std::remove(currentBossMissiles9.begin(), currentBossMissiles9.end(), currentBossMissiles9[i]));
}

void Boss2::deleteBossBullet10(Level1* world, int i){
	world->removeChild(currentBossMissiles10[i]);
	currentBossMissiles10.erase(std::remove(currentBossMissiles10.begin(), currentBossMissiles10.end(), currentBossMissiles10[i]));
}

void Boss2::deleteBossBullet11(Level1* world, int i){
	world->removeChild(currentBossMissiles11[i]);
	currentBossMissiles11.erase(std::remove(currentBossMissiles11.begin(), currentBossMissiles11.end(), currentBossMissiles11[i]));
}

void Boss2::deleteBossBullet12(Level1* world, int i){
	world->removeChild(currentBossMissiles12[i]);
	currentBossMissiles12.erase(std::remove(currentBossMissiles12.begin(), currentBossMissiles12.end(), currentBossMissiles12[i]));
}


void Boss2::update(Level1* world){
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
		Vec2((10 * lives) / 10, 10),
		Vec2((10 * lives) / 10, 0),
		Vec2(0, 0)
	};
	rectWithBorder2->drawPolygon(vertices2, 4, Color4F(0.0f, 1.0f, 0.0f, 1), 3, Color4F(0.0f, 0.0f, 0.0f, .5));

	CCSize s = CCDirector::sharedDirector()->getWinSize();
		//blue bullets
		for (int i = 0; i < currentBossMissiles.size(); i++){
			if (currentBossMissiles[i]->getRemove()){
				deleteBossBullet(world, i);
			}
			else currentBossMissiles[i]->update1();
		}
		if (bossBulletCounter % (SECOND) == 0){
			Missile *missile = Missile::createMissile();
			currentBossMissiles.push_back(missile);
			missile->setPosition(getPosition().x, getPosition().y);
			world->addChild(missile, 3);
			bossBulletCounter = 0;
		}
		for (int i = 0; i < currentBossMissiles2.size(); i++){
			if (currentBossMissiles2[i]->getRemove()){
				deleteBossBullet2(world, i);
			}
			else currentBossMissiles2[i]->update2();
		}
		if (bossBulletCounter % (SECOND) == 0){
			Missile *missile = Missile::createMissile();
			currentBossMissiles2.push_back(missile);
			missile->setPosition(getPosition().x, getPosition().y);
			world->addChild(missile, 3);
			bossBulletCounter = 0;
		}
		for (int i = 0; i < currentBossMissiles3.size(); i++){
			if (currentBossMissiles3[i]->getRemove()){
				deleteBossBullet3(world, i);
			}
			else currentBossMissiles3[i]->update3();
		}
		if (bossBulletCounter % (SECOND) == 0){
			Missile *missile = Missile::createMissile();
			currentBossMissiles3.push_back(missile);
			missile->setPosition(getPosition().x, getPosition().y);
			world->addChild(missile, 3);
			bossBulletCounter = 0;
		}
		for (int i = 0; i < currentBossMissiles4.size(); i++){
			if (currentBossMissiles4[i]->getRemove()){
				deleteBossBullet4(world, i);
			}
			else currentBossMissiles4[i]->update4();
		}
		if (bossBulletCounter % (SECOND) == 0){
			Missile *missile = Missile::createMissile();
			currentBossMissiles4.push_back(missile);
			missile->setPosition(getPosition().x, getPosition().y);
			world->addChild(missile, 3);
			bossBulletCounter = 0;
		}
	if (lives <= 80){
		//yellow bullets
		for (int i = 0; i < currentBossMissiles5.size(); i++){
			if (currentBossMissiles5[i]->getRemove()){
				deleteBossBullet5(world, i);
			}
			else currentBossMissiles5[i]->update5();
		}
		if (bossBulletCounter2 % (SECOND * 2) == 0){
			Missile *missile = Missile::createMissile2();
			currentBossMissiles5.push_back(missile);
			missile->setPosition(getPosition().x, getPosition().y);
			world->addChild(missile, 3);
			bossBulletCounter2 = 0;
		}
		for (int i = 0; i < currentBossMissiles6.size(); i++){
			if (currentBossMissiles6[i]->getRemove()){
				deleteBossBullet6(world, i);
			}
			else currentBossMissiles6[i]->update6();
		}
		if (bossBulletCounter2 % (SECOND * 2) == 0){
			Missile *missile = Missile::createMissile2();
			currentBossMissiles6.push_back(missile);
			missile->setPosition(getPosition().x, getPosition().y);
			world->addChild(missile, 3);
			bossBulletCounter2 = 0;
		}
		for (int i = 0; i < currentBossMissiles7.size(); i++){
			if (currentBossMissiles7[i]->getRemove()){
				deleteBossBullet7(world, i);
			}
			else currentBossMissiles7[i]->update7();
		}
		if (bossBulletCounter2 % (SECOND * 2) == 0){
			Missile *missile = Missile::createMissile2();
			currentBossMissiles7.push_back(missile);
			missile->setPosition(getPosition().x, getPosition().y);
			world->addChild(missile, 3);
			bossBulletCounter2 = 0;
		}
		for (int i = 0; i < currentBossMissiles8.size(); i++){
			if (currentBossMissiles8[i]->getRemove()){
				deleteBossBullet8(world, i);
			}
			else currentBossMissiles8[i]->update8();
		}
		if (bossBulletCounter2 % (SECOND * 2) == 0){
			Missile *missile = Missile::createMissile2();
			currentBossMissiles8.push_back(missile);
			missile->setPosition(getPosition().x, getPosition().y);
			world->addChild(missile, 3);
			bossBulletCounter2 = 0;
		}
	}

	if (lives <= 50){
		//yellow bullets
		for (int i = 0; i < currentBossMissiles9.size(); i++){
			if (currentBossMissiles9[i]->getRemove()){
				deleteBossBullet9(world, i);
			}
			else currentBossMissiles9[i]->update9();
		}
		if (bossBulletCounter3 % (SECOND * 4) == 0){
			Missile *missile = Missile::createMissile3();
			currentBossMissiles9.push_back(missile);
			missile->setPosition(getPosition().x, getPosition().y);
			world->addChild(missile, 3);
			bossBulletCounter3 = 0;
		}
		for (int i = 0; i < currentBossMissiles10.size(); i++){
			if (currentBossMissiles10[i]->getRemove()){
				deleteBossBullet10(world, i);
			}
			else currentBossMissiles10[i]->update10();
		}
		if (bossBulletCounter3 % (SECOND * 4) == 0){
			Missile *missile = Missile::createMissile3();
			currentBossMissiles10.push_back(missile);
			missile->setPosition(getPosition().x, getPosition().y);
			world->addChild(missile, 3);
			bossBulletCounter3 = 0;
		}
		for (int i = 0; i < currentBossMissiles11.size(); i++){
			if (currentBossMissiles11[i]->getRemove()){
				deleteBossBullet11(world, i);
			}
			else currentBossMissiles11[i]->update11();
		}
		if (bossBulletCounter3 % (SECOND * 4) == 0){
			Missile *missile = Missile::createMissile3();
			currentBossMissiles11.push_back(missile);
			missile->setPosition(getPosition().x, getPosition().y);
			world->addChild(missile, 3);
			bossBulletCounter3 = 0;
		}
		for (int i = 0; i < currentBossMissiles12.size(); i++){
			if (currentBossMissiles12[i]->getRemove()){
				deleteBossBullet12(world, i);
			}
			else currentBossMissiles12[i]->update12();
		}
		if (bossBulletCounter3 % (SECOND * 4) == 0){
			Missile *missile = Missile::createMissile3();
			currentBossMissiles12.push_back(missile);
			missile->setPosition(getPosition().x, getPosition().y);
			world->addChild(missile, 3);
			bossBulletCounter3 = 0;
		}
	}

	setPosition(Vec2(s.width / 2, s.height / 2));
		
	//make boss look l
	if (bossCounter >= 30){
		setRotation(5.0f);
	}
	if (bossCounter >= 60){
		// rotate sprite by -20 degrees
		setRotation(-10.0f);
		bossCounter = 0;
	}

	bossCounter++;
	bossBulletCounter++;
	bossBulletCounter2++;
	bossBulletCounter3++;
}

float Boss2::getLives(){
	return lives;
}

void Boss2::loseLives(){
	lives--;
}

void Boss2::initBoss2(){
	lives = 90;
	bossCounter = 0;
	bossBulletCounter = 0;

	rectWithBorder = DrawNode::create();
	Vec2 vertices[] =
	{
		Vec2(0, 10),
		Vec2(100, 10),
		Vec2(100, 0),
		Vec2(0, 0)
	};
	rectWithBorder->setPosition(getPosition().x + 10, getPosition().y - 10);
	rectWithBorder->drawPolygon(vertices, 4, Color4F(1.0f, 0.0f, 0.0f, 1), 3, Color4F(0.0f, 0.0f, 0.0f, 0));
	addChild(rectWithBorder);

	rectWithBorder2 = DrawNode::create();
	Vec2 vertices2[] =
	{
		Vec2(0, 10),
		Vec2((10 * lives) / 10, 10),
		Vec2((10 * lives) / 10, 0),
		Vec2(0, 0)
	};
	rectWithBorder2->setPosition(getPositionX() + 10, getPosition().y  - 10);
	rectWithBorder2->drawPolygon(vertices2, 4, Color4F(0.0f, 1.0f, 0.0f, 1), 3, Color4F(0.0f, 0.0f, 0.0f, .5));
	addChild(rectWithBorder2);
}