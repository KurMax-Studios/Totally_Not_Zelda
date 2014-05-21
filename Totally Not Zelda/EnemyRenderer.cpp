#include "EnemyRenderer.h"


EnemyRenderer::EnemyRenderer(EnemyManager& enemyManager) : m_enemyManager(enemyManager)
{
}


EnemyRenderer::~EnemyRenderer(void)
{
}

void EnemyRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	const std::vector<Enemy*> &enemies = m_enemyManager.getEnemies();
	
}