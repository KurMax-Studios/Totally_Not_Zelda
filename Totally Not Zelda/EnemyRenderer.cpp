#include "EnemyRenderer.h"


EnemyRenderer::EnemyRenderer(EnemyManager& enemyManager) : m_enemyManager(enemyManager)
{
}


EnemyRenderer::~EnemyRenderer(void)
{
}

void EnemyRenderer::init()
{
	//This should in a future version this should be loaded from a file instead of hardcoded
	if(!m_textures["BASIC_ENEMY"].loadFromFile("BasicEnemy.gif"))
	{
		std::cout << "Loading sprite failed!" << std::endl;
		exit(1);
	}
	if(!m_textures["TEST_ENEMY"].loadFromFile("TestEnemy.gif"))
	{
		std::cout << "Loading sprite failed!" << std::endl;
		exit(1);
	}
}
void EnemyRenderer::update()
{
}

void EnemyRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	const std::vector<Enemy*> &enemies = m_enemyManager.getEnemies();
	sf::Sprite enemy;
	for(size_t i=0; i < enemies.size(); i++)
	{
		if(m_textures.count(enemies[i]->getSprite()) == 0) //If the sprite requested does not match anything, use the default
		{
			enemy.setTexture(m_textures.find("BASIC_ENEMY")->second);
		}
		else //If the sprite exists, get the correct one
		{
			enemy.setTexture(m_textures.find(enemies[i]->getSprite())->second);
		}
		enemy.setPosition(enemies[i]->getPosition());
		target.draw(enemy);
	}
}