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
	m_keys[Controls::ATTACK] = sf::Keyboard::Space;
	m_keys[Controls::DEFEND] = sf::Keyboard::C;
}

void PlayerController::update()
{
	readInput();
	executeCommands();
}

void PlayerController::readInput()
{
	if(sf::Keyboard::isKeyPressed(m_keys[DEFEND]))
		m_player.defend();//call defend function
	else if(sf::Keyboard::isKeyPressed(m_keys[SPRINT]))
		m_player.setSpeed(3.0f);
	else{
		m_player.setSpeed(1.0f);
		m_player.setDefending(false);
	}

	if(sf::Keyboard::isKeyPressed(m_keys[ATTACK]))
		m_player.attack();//call attack function

	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_UP]))
		m_player.move(sf::Vector2f(0.0f, -m_player.getSpeed()));
	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_DOWN]))
		m_player.move(sf::Vector2f(0.0f, m_player.getSpeed()));
	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_LEFT]))
		m_player.move(sf::Vector2f(-m_player.getSpeed(), 0.0f));
	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_RIGHT]))
		m_player.move(sf::Vector2f(m_player.getSpeed(), 0.0f));
}	
void PlayerController::executeCommands()
{

}