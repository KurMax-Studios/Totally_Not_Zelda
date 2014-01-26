#pragma once
#include <vector>
#include "SFML\Graphics.hpp"

/*
*	Class for loading resources such as sprites and fonts on program start
*	Class also contains functions for acessing those resources as well as unloading them on destruction
*/
class ResourceManager
{
public:
	ResourceManager(void);
	~ResourceManager(void);

	void init(); //Loads all the data, should be threaded


private:
	std::vector<sf::Image> m_sprites;

};

