#pragma once
#include "Enemy.h"
class TestEnemy :
	public Enemy
{
public:
	TestEnemy(void);
	virtual ~TestEnemy(void);
	virtual void update();
};

