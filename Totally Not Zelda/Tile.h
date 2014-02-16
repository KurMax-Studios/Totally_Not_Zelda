#pragma once
class Tile
{
public:
	Tile();
	explicit Tile(int); // explicit so that we get no accidental conversions
	~Tile(void);

	int id;
};

