#pragma once

#include "cocos2d.h"

class HealthBar : public cocos2d::Sprite{
public:
	static HealthBar * create(void);
	void update();

private:

};
