#pragma once
#include <string>
#include "SFML\System\Vector2.hpp"
class Enemy
{
public:
	Enemy(void);
	virtual ~Enemy(void);
	virtual void update() = 0;
	bool isAlive() const;
	void changeHealth(int);

	std::string getSprite();
	void setSprite(std::string);

	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f);

	sf::Vector2f getVelocity() const;
	void setVelocity(sf::Vector2f);

	sf::Vector2i getSize() const;
protected:
	int m_health;
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2i m_size;
	std::string m_spriteName;
};

