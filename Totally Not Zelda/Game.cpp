#include "Game.h"


Game::Game(void) : m_mapRenderer(m_map), m_playerRenderer(m_player), m_playerController(m_player)
{
}


Game::~Game(void)
{
}

void Game::start()
{
	init();
	while(m_running)
	{
		update();
		draw();
	}
	cleanup();
}

void Game::init()
{
	m_map.loadFromFile("mapBase64.tmx");

	m_mapRenderer.init();
	m_playerRenderer.init();
	m_playerController.init();

	//setup the main window
	m_window.create(sf::VideoMode(800, 600), "Totally Not Zelda");
	m_window.setFramerateLimit(60);

	m_view.setSize(m_window.getSize().x/2, m_window.getSize().y/2);

	m_player.setPosition(sf::Vector2f(100, 200));

	m_debugOverlay.styleText(m_debugOverlay.initFont(), m_debugOverlay.m_fps);
	m_running = true;
}
void Game::update()
{
	sf::Event event;
    while (m_window.pollEvent(event))
    {
		if (event.type == sf::Event::Closed)
		{
			m_running = false;
		}
	}
	m_playerController.update();
	m_playerRenderer.update();
}
void Game::draw()
{
	m_window.clear(sf::Color::Magenta);
	//set the view to center on the player
	m_view.setCenter(m_player.getPosition());
	m_window.setView(m_view);

	//Draw everything in the game world here
	m_window.draw(m_mapRenderer);
	m_window.draw(m_playerRenderer);

	//Restore the deafult view to draw static elements and ui
	m_window.setView(m_window.getDefaultView());

	//Draw static elements and ui
	m_window.draw(m_debugOverlay);

	m_window.display();

	m_fpsCounter.countFrame();
}
void Game::cleanup()
{
}


