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