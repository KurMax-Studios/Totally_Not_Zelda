#include "Player.h"


Player::Player(void)
{
	m_speed = 1.0f;
	//TODO: This should probably not be hardcoded
	m_size = sf::Vector2i(32, 32);
	m_orientation = Orientation::DOWN;
	m_velocity = sf::Vector2f(0, 0);
}


Player::~Player(void)
{
}

void Player::update()
{
	move(m_velocity);
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

void Player::setVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
}
sf::Vector2f Player::getVelocity()
{
	return m_velocity;
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

sf::Vector2i Player::getSize() const
{
	return m_size;
}

void Player::attack()
{
	//TODO attack something maybe
	std::cout << "FEARSOME ATTACK!!!!!" << std::endl;
}

void Player::defend()
{
	//TODO defend tha shit out of stuff
	setSpeed(0.2f);
	setDefending(true);
}

Player::Orientation Player::getOrientation()
{
	return m_orientation;
}
void Player::setOrientation(Player::Orientation orientation)
{
	m_orientation = orientation;
}