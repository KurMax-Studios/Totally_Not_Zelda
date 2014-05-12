#include "MapRenderer.h"


MapRenderer::MapRenderer(Map& map) : m_map(map)
{

}


MapRenderer::~MapRenderer(void)
{
}

void MapRenderer::init()
{
	m_tileset.loadFromTilesetInfo(m_map.getTilesetInfo());
}

void MapRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(int x=0; x < m_map.getMapSize().x; x++)
	{
		for(int y=0; y < m_map.getMapSize().y; y++)
		{
			int tileId = m_map.getTile(sf::Vector2i(x, y)).id;
			sf::Sprite sprite = m_tileset.getSprite(tileId);
			sprite.setPosition(sf::Vector2f((float)x*m_tileset.getTilesetInfo().tileSize.x, (float)y*m_tileset.getTilesetInfo().tileSize.y) + this->getPosition());
			target.draw(sprite);
		}
	}
}