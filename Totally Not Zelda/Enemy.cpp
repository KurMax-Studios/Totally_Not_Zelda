#include "Enemy.h"


Enemy::Enemy(void)
{
	m_spriteName = "BASIC_ENEMY";
}


Enemy::~Enemy(void)
{
}

bool Enemy::isAlive() const
{
	if(m_health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Enemy::changeHealth(int ammount)
{
	m_health += ammount;
}

std::string Enemy::getSprite()
{
	return m_spriteName;
}
void Enemy::setSprite(std::string spriteName)
{
	m_spriteName = spriteName;
}

sf::Vector2f Enemy::getPosition() const
{
	return m_position;
}
void Enemy::setPosition(sf::Vector2f pos)
{
	m_position = pos;
}

sf::Vector2f Enemy::getVelocity() const
{
	return m_velocity;
}
void Enemy::setVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
}

int Enemy::getSize() const
{
	return m_size;
}