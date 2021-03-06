﻿#include "Tileset.h"


Tileset::Tileset(void)
{
}


Tileset::~Tileset(void)
{
}

void Tileset::loadFromTilesetInfo(TilesetInfo info)
{
	m_tileSetinfo = info;
	
	//Load the whole tileset from disk
	if(!m_texture.loadFromFile(m_tileSetinfo.filePath))
	{
		std::cout << "Loading Tileset Image failed! Path: " << m_tileSetinfo.filePath << std::endl;
		exit(1);
	}
}

sf::Sprite Tileset::getSprite(int id) const
{

	sf::Sprite sprite(m_texture);
	id = id - m_tileSetinfo.firstId;

	
	//Calculate the grid coordinates
	int gridY = (id*(m_tileSetinfo.tileSize.x + m_tileSetinfo.spacing)) / (m_texture.getSize().x - (2*m_tileSetinfo.margin));

	int gridX = ((id*(m_tileSetinfo.tileSize.x + m_tileSetinfo.spacing)) % (m_texture.getSize().x - (2*m_tileSetinfo.margin)))/m_tileSetinfo.tileSize.x;
	//IT FUCKING WORKS!

	//Convert them into actual pixel coords
	
	int yPos = (gridY * (m_tileSetinfo.tileSize.y + m_tileSetinfo.spacing)) + (m_tileSetinfo.margin);
	int xPos = (gridX * (m_tileSetinfo.tileSize.y + m_tileSetinfo.spacing)) + (m_tileSetinfo.margin);
	
	sprite.setTextureRect(sf::IntRect(xPos, yPos, m_tileSetinfo.tileSize.x, m_tileSetinfo.tileSize.y));


	
	return sprite;
}

TilesetInfo Tileset::getTilesetInfo() const
{
	return m_tileSetinfo;
}