#include "CollisionManager.h"


CollisionManager::CollisionManager(Player &player, Map &map, EnemyManager &enemyManager) : m_player(player), m_map(map), m_enemyManager(enemyManager)
{
}


CollisionManager::~CollisionManager(void)
{
}

void CollisionManager::update()
{
	checkCollisions();
}

void CollisionManager::checkCollisions()
{
	checkBounds();
	checkTerrain();
}
void CollisionManager::checkBounds()
{
	//Check if the player is outside the map
	if(m_player.getPosition().x < 0)
	{
		m_player.setPosition(sf::Vector2f(0.1f, m_player.getPosition().y));
	}
	if(m_player.getPosition().y < 0)
	{
		m_player.setPosition(sf::Vector2f(m_player.getPosition().x, 0.1f));
	}
	if(m_player.getPosition().x + m_player.getSize().x > m_map.getMapXSize())
	{
		m_player.setPosition(sf::Vector2f(m_map.getMapXSize() - (0.1f + m_player.getSize().x), m_player.getPosition().y));
	}
	if(m_player.getPosition().y + m_player.getSize().y > m_map.getMapYSize())
	{
		m_player.setPosition(sf::Vector2f(m_player.getPosition().x, m_map.getMapYSize() - (0.1f + m_player.getSize().x)));
	}
	//Check if any enemies are outside the map
	const std::vector<Enemy*>& enemies = m_enemyManager.getEnemies();
	for(size_t i = 0;  i < enemies.size(); i++)
	{
		if(enemies[i]->getPosition().x < 0)
		{
			enemies[i]->setPosition(sf::Vector2f(0.1f, enemies[i]->getPosition().y));
		}
		if(enemies[i]->getPosition().y < 0)
		{
			enemies[i]->setPosition(sf::Vector2f(enemies[i]->getPosition().x, 0.1f));
		}
		if(enemies[i]->getPosition().x + enemies[i]->getSize().x > m_map.getMapXSize())
		{
			enemies[i]->setPosition(sf::Vector2f(m_map.getMapXSize() - (0.1f + enemies[i]->getSize().x), enemies[i]->getPosition().y));
		}
		if(enemies[i]->getPosition().y + enemies[i]->getSize().y > m_map.getMapYSize())
		{
			enemies[i]->setPosition(sf::Vector2f(enemies[i]->getPosition().x, m_map.getMapYSize() - (0.1f + enemies[i]->getSize().x)));
		}
	}
}
void CollisionManager::checkTerrain()
{
	int topLeftTile, topRightTile, bottomLeftTile, bottomRightTile;
	sf::Vector2f tempPosition;
	bool collided = false;

	topLeftTile = m_map.getTile(m_map.convertWorldCoordToMapCoords(m_player.getPosition())).id;
	if(m_map.getTilesetInfo().isTileSolid(topLeftTile))
	{
		collided = true;
	}

	//Set the position to the upper right corner
	tempPosition.x = m_player.getPosition().x + m_player.getSize().x;
	tempPosition.y = m_player.getPosition().y;
	topRightTile = m_map.getTile(m_map.convertWorldCoordToMapCoords(tempPosition)).id;
	if(m_map.getTilesetInfo().isTileSolid(topRightTile))
	{
		collided = true;
	}

	//set the position to the lower left corner
	tempPosition.x = m_player.getPosition().x;
	tempPosition.y = m_player.getPosition().y + m_player.getSize().y;
	bottomLeftTile = m_map.getTile(m_map.convertWorldCoordToMapCoords(tempPosition)).id;
	if(m_map.getTilesetInfo().isTileSolid(bottomLeftTile))
	{
		collided = true;
	}

	//set the position to the lower right  corner
	tempPosition.x = m_player.getPosition().x + m_player.getSize().x;
	tempPosition.y = m_player.getPosition().y + m_player.getSize().y;
	bottomRightTile = m_map.getTile(m_map.convertWorldCoordToMapCoords(tempPosition)).id;
	if(m_map.getTilesetInfo().isTileSolid(bottomRightTile))
	{
		collided = true;
	}
	if(collided)
	{
		m_player.move(-m_player.getVelocity());
	}
}