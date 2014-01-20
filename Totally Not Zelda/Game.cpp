#include "Game.h"


Game::Game(void)
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
	//Load shit
	//setup the main window
	m_window.create(sf::VideoMode(800, 600), "Totally Not Zelda");
	m_window.setFramerateLimit(60);

	m_running = true;
}
void Game::update()
{
	//Do shit
	sf::Event event;
    while (m_window.pollEvent(event))
    {
		if (event.type == sf::Event::Closed)
		{
			m_running = false;
		}
	}
}
void Game::draw()
{
	//Draw shit
	m_window.clear(sf::Color::Magenta);
	//DRAW STUFF HERE
	m_window.display();
}
void Game::cleanup()
{
	//unload shit
}


