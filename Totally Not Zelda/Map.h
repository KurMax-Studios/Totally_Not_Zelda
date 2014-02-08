#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "SFML\System\Vector2.hpp"
#include "rapidxml.hpp"
#include "Tile.h"
class Map
{
public:
	Map(void);
	~Map(void);

	void loadFromFile(std::string filename);
private:
	sf::Vector2i m_mapSize;
	sf::Vector2i m_tileSize;

	std::map<sf::Vector2i, Tile> m_tiles;
};

