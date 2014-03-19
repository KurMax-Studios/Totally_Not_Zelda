#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include "FpsCounter.h"
#include "Map.h"
#include "MapRenderer.h"
#include "DebugOverlay.h"
#include "Player.h"
#include "PlayerRenderer.h"
#include "PlayerController.h"
#include "Options.h"
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
	DebugOverlay m_debugOverlay;
	Options m_options;

	MapRenderer m_mapRenderer;
	PlayerRenderer m_playerRenderer;

	PlayerController m_playerController;

	bool m_running;
	sf::RenderWindow m_window;
	sf::View m_view;

	int m_windowX;
	int m_windowY;
};

