#pragma once
#include "SFML\System\Vector2.hpp"
#include <iostream>
class Player
{
public:
	Player(void);
	~Player(void);
	enum Orientation
	{
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

	void update();

	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f);
	void setSpeed(float speed);
	float getSpeed();

	void setVelocity(sf::Vector2f);
	sf::Vector2f getVelocity();

	sf::Vector2i getSize() const;
	void move(sf::Vector2f);	
	void attack();
	void defend();
	bool isDefending();
	void setDefending(bool state);
	Orientation getOrientation();
	void setOrientation(Orientation);

private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2i m_size;
	float m_speed;
	bool m_defending;
	Orientation m_orientation;
};

