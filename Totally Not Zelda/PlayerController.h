#pragma once
#include <vector>
#include "SFML\Window.hpp"
#include "Player.h"
class PlayerController
{
public:
	PlayerController(Player&);
	~PlayerController(void);
	void init();
	void update();
private:
	void readInput();
	enum Controls
	{
		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT, 
		MOVE_RIGHT,
		SPRINT,
		NUM_VALUES
	};
	Player &m_player;
	std::vector<sf::Keyboard::Key> m_keys;
	float m_speed;
};

