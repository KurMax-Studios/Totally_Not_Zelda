#include "EnemyManager.h"


EnemyManager::EnemyManager(void)
{
}


EnemyManager::~EnemyManager(void)
{
	for(size_t i=0; i < m_enemies.size(); i++)
	{
		delete m_enemies[i];
	}
}

void EnemyManager::update()
{
	for(size_t i=0; i < m_enemies.size(); i++)
	{
		if(m_enemies[i] != 0x0)
		{
			m_enemies[i]->update();
		}
	}
}

const std::vector<Enemy*>& EnemyManager::getEnemies() const
{
	return m_enemies;
}