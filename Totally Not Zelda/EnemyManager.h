#pragma once
#include <vector>
#include "Enemy.h"
class EnemyManager
{
public:
	EnemyManager(void);
	~EnemyManager(void);
	void update();
private:
	std::vector<Enemy*> m_enemies;
};

