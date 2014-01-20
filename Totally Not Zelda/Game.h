#pragma once
#include "SFML\Graphics.hpp"
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

	
	bool m_running;
	sf::RenderWindow m_window;

};

