#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include "FpsCounter.h"
#include "Map.h"
#include "MapRenderer.h"
#include "Player.h"
#include "PlayerRenderer.h"
class Game
{
public:
	Game(void);
	~Game(void);

	void start();
private:
	void init();
	void update();
	void draw();
	void cleanup();

	Map m_map;
	Player m_player;
	FpsCounter m_fpsCounter;

	MapRenderer m_mapRenderer;
	PlayerRenderer m_playerRenderer;

	bool m_running;
	sf::RenderWindow m_window;
	sf::View m_view;

};

