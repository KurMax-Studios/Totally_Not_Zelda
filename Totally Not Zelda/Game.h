#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include "FpsCounter.h"
#include "Map.h"
#include "MapRenderer.h"
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
	FpsCounter m_fpsCounter;

	MapRenderer m_mapRenderer;

	bool m_running;
	sf::RenderWindow m_window;

};

