#pragma once
#include "SFML\Graphics.hpp"
#include "Map.h"
#include "Tileset.h"
class MapRenderer : 
	public sf::Drawable, 
	public sf::Transformable
{
public:
	MapRenderer(Map&);
	~MapRenderer(void);

	void init();
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	Tileset m_tileset;
	Map& m_map;
};

