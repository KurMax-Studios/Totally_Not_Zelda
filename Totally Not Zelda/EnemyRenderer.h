#pragma once
#include "Enemy.h"
#include "EnemyManager.h"
class EnemyRenderer
{
public:
	EnemyRenderer(EnemyManager&);
	~EnemyRenderer(void);
private:
	EnemyManager& m_enemyManager;
};