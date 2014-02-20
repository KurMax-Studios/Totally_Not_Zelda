#include "Tileset.h"


Tileset::Tileset(void)
{
}


Tileset::~Tileset(void)
{
}

void Tileset::loadFromTilesetInfo(TilesetInfo info)
{
	m_tileSetinfo = info;
	if(!m_texture.loadFromFile(m_tileSetinfo.filePath))
	{
		std::cout << "Loading Tileset Image failed! Path: " << m_tileSetinfo.filePath << std::endl;
		exit(1);
	}

}

sf::Sprite Tileset::getSprite(int id)
{
	sf::Sprite sprite(m_texture);

	//Find our what row and colomn our tile is in
	int yPos = id / m_texture.getSize().y;
	int xPos = id % m_texture.getSize().x;

	sprite.setTextureRect(sf::IntRect(0, 0, m_tileSetinfo.imageSize.x, m_tileSetinfo.imageSize.y));

	return sprite;
}