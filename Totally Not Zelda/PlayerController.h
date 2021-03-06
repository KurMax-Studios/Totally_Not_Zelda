#pragma once
#include <vector>
#include "SFML\Window.hpp"
#include "Player.h"
#include "Options.h"
class PlayerController
{
public:
	PlayerController(Player&, Options&);
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
		ATTACK,
		DEFEND,
		NUM_VALUES
	};
	Player &m_player;
	Options &m_options;
	std::vector<sf::Keyboard::Key> m_keys;
};

