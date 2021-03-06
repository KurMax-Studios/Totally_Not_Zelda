#pragma once
#include <vector>
#include "Enemy.h"
class EnemyManager
{
public:
	EnemyManager(void);
	~EnemyManager(void);
	void update();

	void addEnemy(Enemy*);

	const std::vector<Enemy*>& getEnemies() const;
private:
	std::vector<Enemy*> m_enemies;
};