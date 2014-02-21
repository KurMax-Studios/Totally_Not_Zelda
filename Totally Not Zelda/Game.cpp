#include "Game.h"


Game::Game(void) : m_mapRenderer(m_map)
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

	//setup the main window
	m_window.create(sf::VideoMode(800, 600), "Totally Not Zelda");
	m_window.setFramerateLimit(60);

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

	//std::cout << m_fpsCounter.getRoundedFps() << std::endl;
}
void Game::draw()
{
	m_window.clear(sf::Color::Magenta);
	//DRAW STUFF HERE
	m_window.draw(m_mapRenderer);
	m_window.display();
	m_fpsCounter.countFrame();
}
void Game::cleanup()
{
}


