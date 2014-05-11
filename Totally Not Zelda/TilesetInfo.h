#pragma once
#include <string>
#include <map>
#include "SFML\System\Vector2.hpp"
class TilesetInfo
{
public:
	TilesetInfo();
	~TilesetInfo();

	void setTileSolid(int, bool);

	bool isTileSolid(int); //id as a gid

	std::string name;
	int firstId;
	sf::Vector2i tileSize;
	int spacing;
	int margin;
	std::string filePath;
	sf::Vector2i imageSize;

private:
	struct TileProperties
	{
		TileProperties(){ solid = false; };
		bool solid;
	};
	std::map<int, TileProperties> m_tileProperties;
};