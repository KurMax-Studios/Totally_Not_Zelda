#pragma once
#include <string>
#include "SFML\System\Vector2.hpp"
class TilesetInfo
{
public:
	std::string name;
	int firstId;
	sf::Vector2i tileSize;
	int spacing;
	int margin;
	std::string filePath;
	sf::Vector2f imageSize;
};

