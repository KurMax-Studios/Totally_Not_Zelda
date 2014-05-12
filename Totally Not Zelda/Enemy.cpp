#include "Enemy.h"


Enemy::Enemy(void)
{
}


Enemy::~Enemy(void)
{
}

bool Enemy::isAlive()
{
	if(m_health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Enemy::changeHealth(int ammount)
{
	m_health += ammount;
}
