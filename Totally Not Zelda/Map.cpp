#include "Map.h"


Map::Map(void)
{
}


Map::~Map(void)
{
}

void Map::loadFromFile(std::string filename)
{
	//Load the map file into memory
	std::ifstream file(filename);
	if(!file.is_open())
	{
		std::cout << "Map file could not be loaded" << std::endl;
		exit(1);
	}
	std::string rawMapDataString((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

	//Convert to char array since rapidxml wont accept const char*
	char* rawMapData = new char[rawMapDataString.size()+1]; // +1 since we need space for the null terminator
	strcpy_s(rawMapData, sizeof(char)*rawMapDataString.size()+1 ,rawMapDataString.c_str());

	rapidxml::xml_document<> mapData;
	mapData.parse<0>(rawMapData);

	//Load map properties
	std::string mapWidth = mapData.first_node("map")->first_attribute("width")->value();
	std::string mapHeight = mapData.first_node("map")->first_attribute("height")->value();
	
	
	//Convert the resulting strings to ints and store them
	m_mapSize.x = std::stoi(mapWidth);
	m_mapSize.y = std::stoi(mapHeight);

	//Resize the m_tiles vectors to fit the map
	m_tiles.resize(m_mapSize.y);
	for(size_t i=0; i < m_tiles.size(); i++)
	{
		m_tiles[i].resize(m_mapSize.x);
	}

	//Load tileset properties
	rapidxml::xml_node<> *tileset = mapData.first_node("map")->first_node("tileset");
	m_tilesetInfo.firstId = std::stoi(tileset->first_attribute("firstgid")->value());
	m_tilesetInfo.name = tileset->first_attribute("name")->value();
	m_tilesetInfo.tileSize.x = std::stoi(tileset->first_attribute("tilewidth")->value());
	m_tilesetInfo.tileSize.y = std::stoi(tileset->first_attribute("tileheight")->value());
	m_tilesetInfo.spacing = std::stoi(tileset->first_attribute("spacing")->value());
	m_tilesetInfo.margin = std::stoi(tileset->first_attribute("margin")->value());
	m_tilesetInfo.filePath = tileset->first_node("image")->first_attribute("source")->value();
	m_tilesetInfo.imageSize.x = std::stoi(tileset->first_node("image")->first_attribute("width")->value());
	m_tilesetInfo.imageSize.y = std::stoi(tileset->first_node("image")->first_attribute("height")->value());

	//Load TileProperties 
	//Itterate over all tiles that have properties set
	for(rapidxml::xml_node<> *tile = tileset->first_node("tile"); tile != 0x0; tile = tile->next_sibling("tile"))
	{
		int id = std::stoi(tile->first_attribute("id")->value());
		rapidxml::xml_node<> *properties = tile->first_node("properties");
		//Itterate over all properties
		for(rapidxml::xml_node<> *property = properties->first_node("property"); property != 0x0; property = property->next_sibling("property"))
		{
			if(strcmp(property->first_attribute("name")->value(), "solid") == 0)
			{
				m_tilesetInfo.setTileSolid(id, (strcmp(property->first_attribute("value")->value(), "true")) == 0);
			}
		}
	}


	//Check if the first layer has any data encoding
	rapidxml::xml_node<> *layerData = mapData.first_node("map")->first_node("layer")->first_node("data");
	if(layerData->first_attribute("encoding") != NULL)
	{
		//Print out encoding info, for debugging
		std::cout << "Encoding: " << layerData->first_attribute("encoding")->value() << std::endl;
		std::cout << "Raw data: " << layerData->value() << std::endl;

		//Since valid base64 should not have whitespace, we remove it from the encoded string incase there are any in the source file
		std::string encodedData = layerData->value();
		encodedData.erase(std::remove_if(encodedData.begin(), encodedData.end(), isspace), encodedData.end());
		std::string decodedData = base64_decode(encodedData);

		if(layerData->first_attribute("compression") != NULL)
		{
			//If the layer has further compression, uncompress the string

			//Compression support will be added at a later time

			std::cout << "Compression: " << layerData->first_attribute("compression")->value() << std::endl;
			
		}

		//Our return string is to be interpreted as an array of unsinged 32 bit integers, NOT as chars
		//Mening that we parse the decoded data 4 bytes at a time
		
		for(size_t i=0; i < decodedData.size(); i+=4)
		{
			unsigned int id = 0;
			//We iterate backwards since the data is stored in a Lowest significant bit first order
			for(int j=3; j >= 0; j--)
			{
				//XOR the bits into the id variable
				id = id ^ decodedData[i+j];
				//The last byte does not need to be shifted
				if(j != 0)
				{
					//Bitshift the data a whole byte to the left
					id = id << 8;
				}
			}
			//i/4 to get the number of tiles since 4 chars makes up 1 id
			int yPos = (i/4) / m_mapSize.y;
			int xPos = (i/4) % m_mapSize.x;
			
			m_tiles[yPos][xPos].id = id;
		}
		
	}
	else
	{
		//If there is no encoding we just iterate over the xml nodes
		rapidxml::xml_node<> *tile = layerData->first_node("tile");
		for(int y=0; y < m_mapSize.y; y++)
		{
			for(int x=0; x < m_mapSize.x; x++)
			{
				m_tiles[y][x].id = std::stoi(tile->first_attribute("gid")->value());
				tile = tile->next_sibling();
			}
		}

		
	}
	//Print out the map
	for(size_t y=0; y < m_tiles.size(); y++)
	{
		for(size_t x=0; x < m_tiles[y].size(); x++)
		{
			std::cout << m_tiles[y][x].id << " ";
		}
		std::cout << std::endl;
	}

	delete[] rawMapData;
}

Tile& Map::getTile(sf::Vector2i pos)
{
	return m_tiles[pos.y][pos.x];
}

TilesetInfo& Map::getTilesetInfo()
{
	return m_tilesetInfo;
}

sf::Vector2i Map::getMapSize()
{
	return m_mapSize;
}
float Map::getMapXSize()
{
	return (float)(m_mapSize.x * m_tilesetInfo.tileSize.x);
}
float Map::getMapYSize()
{
	return (float)(m_mapSize.y * m_tilesetInfo.tileSize.y);
}

sf::Vector2i Map::convertWorldCoordToMapCoords(sf::Vector2f worldCoord)
{
	sf::Vector2i mapCoord;
	mapCoord.x = (int)(worldCoord.x / m_tilesetInfo.tileSize.x); //Explicitly converting to int to make sure we do float divisions
	mapCoord.y = (int)(worldCoord.y / m_tilesetInfo.tileSize.y); //The conversion truncates the value, wich is what we want since we want to know what tile we are in
	return mapCoord;
}