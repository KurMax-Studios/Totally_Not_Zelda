#include "PlayerRenderer.h"


PlayerRenderer::PlayerRenderer(Player& player) : m_player(player)
{
}


PlayerRenderer::~PlayerRenderer(void)
{
}

void PlayerRenderer::init()
{
	if(!m_texture.loadFromFile("hero.gif"))
	{
		std::cout << "Loading sprite failed!" << std::endl;
		exit(1);
	}
	m_playerSprite.setTexture(m_texture);
}

void PlayerRenderer::update()
{
	m_playerSprite.setPosition(m_player.getPosition());
	switch (m_player.getOrientation())
	{
	case Player::Orientation::UP:
		if(!m_texture.loadFromFile("heroUp.gif"))
		{
			std::cout << "Loading sprite failed!" << std::endl;
			exit(1);
		}
		break;
	case Player::Orientation::DOWN:
		if(!m_texture.loadFromFile("hero.gif"))
		{
			std::cout << "Loading sprite failed!" << std::endl;
			exit(1);
		}
		break;
	case Player::Orientation::LEFT:
		if(!m_texture.loadFromFile("heroLeft.gif"))
		{
			std::cout << "Loading sprite failed!" << std::endl;
			exit(1);
		}
		break;
	case Player::Orientation::RIGHT:
		if(!m_texture.loadFromFile("heroRight.gif"))
		{
			std::cout << "Loading sprite failed!" << std::endl;
			exit(1);
		}
		break;
	default:
		break;
	}
}

void PlayerRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_playerSprite);
}