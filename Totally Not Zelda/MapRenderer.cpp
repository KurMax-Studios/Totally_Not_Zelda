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
	sf::Sprite temp = m_tileset.getSprite(9);
	temp.setPosition(200, 300);
	target.draw(temp);
}