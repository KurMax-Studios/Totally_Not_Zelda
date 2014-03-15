#include "Player.h"


Player::Player(void)
{
	//TODO: This should probably not be hardcoded
	m_size = sf::Vector2i(16, 16);
}


Player::~Player(void)
{
}

sf::Vector2f Player::getPosition() const
{
	return m_position;
}
void Player::setPosition(sf::Vector2f position)
{
	m_position = position;
}
void Player::move(sf::Vector2f offset)
{
	m_position += offset;
}

sf::Vector2i Player::getSize() const
{
	return m_size;
}