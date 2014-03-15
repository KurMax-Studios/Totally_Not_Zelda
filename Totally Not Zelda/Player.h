#pragma once
#include "SFML\System\Vector2.hpp"
class Player
{
public:
	Player(void);
	~Player(void);

	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f);
	void move(sf::Vector2f);

	sf::Vector2i getSize() const;
private:
	sf::Vector2f m_position;
	sf::Vector2i m_size;
};

