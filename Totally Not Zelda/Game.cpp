#include "Game.h"


Game::Game(void) : m_mapRenderer(m_map), m_playerRenderer(m_player), m_enemyRenderer(m_enemyManager), m_playerController(m_player, m_options), m_collisionManager(m_player, m_map, m_enemyManager), m_player(m_options)
{
	m_options.initOptions();
	m_windowX = m_options.getOption(Options::SCREEN_X);
	m_windowY = m_options.getOption(Options::SCREEN_Y);
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
	m_enemyRenderer.init();

	m_playerController.init();
	m_debugOverlay.init();

	//setup the main window
	m_window.create(sf::VideoMode(m_windowX, m_windowY), "Totally Not Zelda");
	m_window.setFramerateLimit(60);

	m_view.setSize(m_window.getSize().x/2.0f, m_window.getSize().y/2.0f);

	m_player.setPosition(sf::Vector2f(100, 200));

	m_running = true;

	//TESTING ENEMIES
	//Allocating with new is fine since EnemyManager takes care of dealeting them
	TestEnemy* testEnemy = new TestEnemy();
	testEnemy->setPosition(sf::Vector2f(40, 40));
	m_enemyManager.addEnemy(testEnemy);
	PatrolingEnemy* patrolingEnemy = new PatrolingEnemy();
	patrolingEnemy->setPosition(sf::Vector2f(40, 40));
	m_enemyManager.addEnemy(patrolingEnemy);
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
	m_player.update();
	m_playerRenderer.update();

	m_enemyManager.update();
	m_enemyRenderer.update();

	m_collisionManager.update();

	//TODO think if we should hardcode fps into the function
	m_debugOverlay.updateText(std::to_string(m_fpsCounter.getRoundedFps()), m_debugOverlay.m_fps);
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
	m_window.draw(m_enemyRenderer);

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


