#include "TilesetInfo.h"

TilesetInfo::TilesetInfo()
{
}
TilesetInfo::~TilesetInfo()
{
}

void TilesetInfo::setTileSolid(int id, bool value)
{
	m_tileProperties[id].solid = value;
}

bool TilesetInfo::isTileSolid(int id)
{
	return m_tileProperties[id].solid;
}