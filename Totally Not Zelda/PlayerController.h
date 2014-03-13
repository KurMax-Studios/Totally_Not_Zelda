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
	void executeCommands();
	enum Controls
	{
		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT, 
		MOVE_RIGHT
	};
	Player &m_player;
	std::vector<sf::Keyboard::Key> m_keys;

};

