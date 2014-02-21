#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "SFML\System\Vector2.hpp"
#include "rapidxml.hpp"
#include "base64.h"
#include "Tile.h"
#include "TilesetInfo.h"
class Map
{
public:
	Map(void);
	~Map(void);

	void loadFromFile(std::string filename);
	Tile& getTile(sf::Vector2i);
	TilesetInfo& getTilesetInfo();

private:
	TilesetInfo m_tilesetInfo;
	sf::Vector2i m_mapSize;
	sf::Vector2i m_tileSize;

	std::vector<std::vector<Tile>> m_tiles; //Acsessed [y][x] becuse of how .tmx maps sort tiles
};

