#pragma once
#include <iostream>
#include "TilesetInfo.h"
#include "SFML\Graphics.hpp"
class Tileset
{
public:
	Tileset(void);
	~Tileset(void);

	void loadFromTilesetInfo(TilesetInfo);
	sf::Sprite getSprite(int) const;
	TilesetInfo getTilesetInfo() const;
private:
	TilesetInfo m_tileSetinfo;
	sf::Texture m_texture;
};

