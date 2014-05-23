#pragma once
#include "Enemy.h"
class PatrolingEnemy : public Enemy
{
public:
	PatrolingEnemy(void);
	~PatrolingEnemy(void);
	virtual void update();
private:

};

