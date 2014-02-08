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

	std::cout << rawMapDataString << std::endl;
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


	//Check if the first layer has any data encoding
	rapidxml::xml_node<> *layer = mapData.first_node("map")->first_node("layer")->first_node("data");
	if(layer->first_attribute("encoding") != NULL)
	{

		//Take steps to decode it
		std::cout << "Encoding: " << layer->first_attribute("encoding")->value() << std::endl;

		if(layer->first_attribute("compression") != NULL)
		{
			std::cout << "Compression: " << layer->first_attribute("compression")->value() << std::endl;
		}

	}
	
	

	delete[] rawMapData;
}