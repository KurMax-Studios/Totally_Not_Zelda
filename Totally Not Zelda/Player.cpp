#include "Player.h"


Player::Player(void)
{
	m_speed = 1.0f;
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
void Player::setSpeed(float speed)
{
	m_speed = speed;
}
float Player::getSpeed()
{
	return m_speed;
}
void Player::setDefending(bool state)
{
	m_defending = state;
}
bool Player::isDefending()
{
	return m_defending;
}
void Player::move(sf::Vector2f offset)
{
	m_position += offset;
}
void Player::attack()
{
	//TODO attack something maybe
}
void Player::defend()
{
	//TODO defend tha shit out of stuff
	setSpeed(0.2f);
	setDefending(true);
}