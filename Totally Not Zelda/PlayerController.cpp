#include "PlayerController.h"


PlayerController::PlayerController(Player& player) : m_player(player)
{
	m_keys.resize(NUM_VALUES);
}


PlayerController::~PlayerController(void)
{
}

void PlayerController::init()
{
	m_keys[Controls::MOVE_UP] = sf::Keyboard::W;
	m_keys[Controls::MOVE_DOWN] = sf::Keyboard::S;
	m_keys[Controls::MOVE_LEFT] = sf::Keyboard::A;
	m_keys[Controls::MOVE_RIGHT] = sf::Keyboard::D;
	m_keys[Controls::SPRINT] = sf::Keyboard::LShift;
}

void PlayerController::update()
{
	readInput();
}

void PlayerController::readInput()
{
	if(sf::Keyboard::isKeyPressed(m_keys[SPRINT]))
		m_speed = 3.0f;
	else
		m_speed = 1.0f;

	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_UP]))
		m_player.move(sf::Vector2f(0.0f, -m_speed));
	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_DOWN]))
		m_player.move(sf::Vector2f(0.0f, m_speed));
	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_LEFT]))
		m_player.move(sf::Vector2f(-m_speed, 0.0f));
	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_RIGHT]))
		m_player.move(sf::Vector2f(m_speed, 0.0f));
}