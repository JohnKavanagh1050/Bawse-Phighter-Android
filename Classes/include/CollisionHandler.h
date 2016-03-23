#include "Player.h"
#include "Boss.h"

class CollisionHandler{
public:
	void initBoss();
	void move(int directionParam);
	void update(GameScreen* world);
	void idle();
	void Hit();
	void Defeated();

private:
	std::vector<BossBullet*> currentBossBullets;
};
