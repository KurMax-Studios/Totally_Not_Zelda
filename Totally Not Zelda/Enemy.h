#pragma once
#include "SFML\System\Vector2.hpp"
class Enemy
{
public:
	Enemy(void);
	virtual ~Enemy(void);
	virtual void update() = 0;
	bool isAlive();
	void changeHealth(int);
protected:
	int m_health;
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
};

