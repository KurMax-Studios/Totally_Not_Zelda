#include "CollisionManager.h"


CollisionManager::CollisionManager(Player &player, Map &map) : m_player(player), m_map(map)
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
}
void CollisionManager::checkTerrain()
{
	int topLeftTile, topRightTile, bottomLeftTile, bottomRightTile;
	sf::Vector2f tempPosition;

	topLeftTile = m_map.getTile(m_map.convertWorldCoordToMapCoords(m_player.getPosition())).id;

	//Set the position to the upper right corner
	tempPosition.x = m_player.getPosition().x + m_player.getSize().x;
	tempPosition.y = m_player.getPosition().y;
	topRightTile = m_map.getTile(m_map.convertWorldCoordToMapCoords(tempPosition)).id;

	//set the position to the lower left corner
	tempPosition.x = m_player.getPosition().x;
	tempPosition.y = m_player.getPosition().y + m_player.getSize().y;
	bottomLeftTile = m_map.getTile(m_map.convertWorldCoordToMapCoords(tempPosition)).id;

	//set the position to the lower right  corner
	tempPosition.x = m_player.getPosition().x + m_player.getSize().x;
	tempPosition.y = m_player.getPosition().y + m_player.getSize().y;
	bottomRightTile = m_map.getTile(m_map.convertWorldCoordToMapCoords(tempPosition)).id;
}