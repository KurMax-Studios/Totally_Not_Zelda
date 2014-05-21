#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include "Player.h"
class PlayerRenderer : public sf::Drawable
{
public:
	PlayerRenderer(Player&);
	~PlayerRenderer(void);

	void init();
	void update();
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	Player& m_player;

	sf::Sprite m_playerSprite;
	//TODO: This texture should probably be loaded somewhere else
	sf::Texture m_texture_up;
	sf::Texture m_texture_down;
	sf::Texture m_texture_left;
	sf::Texture m_texture_right;
};

