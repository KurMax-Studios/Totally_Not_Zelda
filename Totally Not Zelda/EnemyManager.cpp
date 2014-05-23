#include "EnemyManager.h"


EnemyManager::EnemyManager(void)
{
}


EnemyManager::~EnemyManager(void)
{
	for(size_t i=0; i < m_enemies.size(); i++)
	{
		delete m_enemies[i];
		m_enemies[i] = 0x0;
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

void EnemyManager::addEnemy(Enemy* enemy)
{
	for(size_t i=0; i < m_enemies.size(); i++)
	{
		if(m_enemies[i] == 0x0)
		{
			m_enemies[i] = enemy;
			break;
		}
	}
	//If we do not find a free spot, make one
	m_enemies.push_back(enemy);
}

const std::vector<Enemy*>& EnemyManager::getEnemies() const
{
	return m_enemies;
}