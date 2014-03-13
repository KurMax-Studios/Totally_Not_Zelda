#include "Player.h"


Player::Player(void)
{
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