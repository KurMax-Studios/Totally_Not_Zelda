#pragma once
#include "SFML\System\Vector2.hpp"
#include <iostream>
class Player
{
public:
	Player(void);
	~Player(void);

	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f);
	void setSpeed(float speed);
	float getSpeed();
	void move(sf::Vector2f);
	void attack();
	void defend();
	bool isDefending();
	void setDefending(bool state);
private:
	sf::Vector2f m_position;
	float m_speed;
	bool m_defending;
};

