#include "Player.h"


Player::Player(Options& options) : m_options(options)
{
	m_speed = 1.0f;
	//TODO: This should probably not be hardcoded
	m_size = sf::Vector2i(32, 32);
	m_orientation = Orientation::DOWN;
	m_velocity = sf::Vector2f(0, 0);
	m_attackCooldown = 0;
	//TODO: Program chrashing when closed, related to sounds
    if (!m_attackSoundBuffer.loadFromFile("attackSound.wav")){
		std::cout << "Could not load attackSound.waw" << std::endl;
		exit(6);
	}
	m_attackSound.setBuffer(m_attackSoundBuffer);
	m_attackSound.setVolume(m_options.getOption(Options::optionNames::VOLUME));
}


Player::~Player(void)
{
}

void Player::update()
{
	move(m_velocity);
	if(m_attackCooldown > 0)
	{
		m_attackCooldown--;
	}
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
	//TODO accualy take less to no damage when attacked by an enemy
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
	//TODO damage on enemys
	if(m_attackCooldown > 0)
	{
		return;
	}
	m_attackSound.play();
	std::cout << "FEARSOME ATTACK!!!!!" << std::endl;
	m_attackCooldown = ATTACK_COOLDOWN;
}

void Player::defend()
{
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