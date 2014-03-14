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
}

void PlayerRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_playerSprite);
}