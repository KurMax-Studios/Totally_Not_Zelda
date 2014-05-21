#include "PlayerRenderer.h"


PlayerRenderer::PlayerRenderer(Player& player) : m_player(player)
{
}


PlayerRenderer::~PlayerRenderer(void)
{
}

void PlayerRenderer::init()
{
	if(!m_texture_up.loadFromFile("heroUp.gif"))
	{
		std::cout << "Loading sprite failed!" << std::endl;
		exit(1);
	}
	if(!m_texture_down.loadFromFile("hero.gif"))
	{
		std::cout << "Loading sprite failed!" << std::endl;
		exit(1);
	}
	if(!m_texture_left.loadFromFile("heroLeft.gif"))
	{
		std::cout << "Loading sprite failed!" << std::endl;
		exit(1);
	}
	if(!m_texture_right.loadFromFile("heroRight.gif"))
	{
		std::cout << "Loading sprite failed!" << std::endl;
		exit(1);
	}
	m_playerSprite.setTexture(m_texture_down);
}

void PlayerRenderer::update()
{
	m_playerSprite.setPosition(m_player.getPosition());
	switch (m_player.getOrientation())
	{
	case Player::Orientation::UP:
		m_playerSprite.setTexture(m_texture_up);
		break;
	case Player::Orientation::DOWN:
		m_playerSprite.setTexture(m_texture_down);
		break;
	case Player::Orientation::LEFT:
		m_playerSprite.setTexture(m_texture_left);
		break;
	case Player::Orientation::RIGHT:
		m_playerSprite.setTexture(m_texture_right);
		break;
	default:
		//This should never happen
		break;
	}
}

void PlayerRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_playerSprite);
}