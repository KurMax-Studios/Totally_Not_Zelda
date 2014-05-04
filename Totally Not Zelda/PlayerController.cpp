#include "PlayerController.h"


PlayerController::PlayerController(Player& player, Options& options) : m_player(player), m_options(options)
{
	m_keys.resize(NUM_VALUES);
}


PlayerController::~PlayerController(void)
{
}

void PlayerController::init()
{
	m_keys[Controls::MOVE_UP] = (sf::Keyboard::Key)m_options.getOption(Options::CONTROLS_UP);
	m_keys[Controls::MOVE_DOWN] = (sf::Keyboard::Key)m_options.getOption(Options::CONTROLS_DOWN);
	m_keys[Controls::MOVE_LEFT] = (sf::Keyboard::Key)m_options.getOption(Options::CONTROLS_LEFT);
	m_keys[Controls::MOVE_RIGHT] = (sf::Keyboard::Key)m_options.getOption(Options::CONTROLS_RIGHT);
	m_keys[Controls::SPRINT] = (sf::Keyboard::Key)m_options.getOption(Options::CONTROLS_SPRINT);
	m_keys[Controls::ATTACK] = (sf::Keyboard::Key)m_options.getOption(Options::CONTROLS_ATTACK);
	m_keys[Controls::DEFEND] = (sf::Keyboard::Key)m_options.getOption(Options::CONTROLS_DEFEND);
}

void PlayerController::update()
{
	readInput();
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
	{
		m_player.setVelocity(sf::Vector2f(0,-m_player.getSpeed()));
		m_player.setOrientation(Player::Orientation::UP);
	}
	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_DOWN]))
	{
		m_player.setVelocity(sf::Vector2f(0,m_player.getSpeed()));
		m_player.setOrientation(Player::Orientation::DOWN);
	}
	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_LEFT]))
	{	
		m_player.setVelocity(sf::Vector2f(-m_player.getSpeed(),0));
		m_player.setOrientation(Player::Orientation::LEFT);
	}
	if(sf::Keyboard::isKeyPressed(m_keys[MOVE_RIGHT]))
	{
		m_player.setVelocity(sf::Vector2f(m_player.getSpeed(),0));
		m_player.setOrientation(Player::Orientation::RIGHT);
	}
	//If none of the movement keys are pressed, stop the player
	if(!sf::Keyboard::isKeyPressed(m_keys[MOVE_UP]) && !sf::Keyboard::isKeyPressed(m_keys[MOVE_DOWN]) && !sf::Keyboard::isKeyPressed(m_keys[MOVE_LEFT]) && !sf::Keyboard::isKeyPressed(m_keys[MOVE_RIGHT]))
	{
		m_player.setVelocity(sf::Vector2f(0, 0));
	}
}	