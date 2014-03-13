#include "PlayerController.h"


PlayerController::PlayerController(Player& player) : m_player(player)
{
	m_keys.resize(4);
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
}

void PlayerController::update()
{
	readInput();
	executeCommands();
}

void PlayerController::readInput()
{
	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_UP]))
		m_player.move(sf::Vector2f(0.0f, -1.0f));
	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_DOWN]))
		m_player.move(sf::Vector2f(0.0f, 1.0f));
	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_LEFT]))
		m_player.move(sf::Vector2f(-1.0f, 0.0f));
	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_RIGHT]))
		m_player.move(sf::Vector2f(1.0f, 0.0f));
}
void PlayerController::executeCommands()
{

}